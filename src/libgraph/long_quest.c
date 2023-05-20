#include <stdio.h>
#include <stdlib.h>

#include <libgraph/input.h>
#include <libgraph/long_quest.h>

// Рекурсивная функция для обхода графа в глубину и нахождения всех путей
void quest_roads(
        int start, int end, Matrix* graph, Roads* target, tackle* quest)
{
    quest->checked[start] = 1;
    quest->path[quest->path_len] = start;
    quest->path_len += 1;

    if (start == end) {
        // Записываем найденный путь в исходную структуру
        for (int i = 0; i < quest->path_len; i++) {
            quest->all_roads[quest->num_roads][i] = quest->path[i];
        }
        quest->all_roads[quest->num_roads][quest->path_len] = -1;
        quest->all_roads[quest->num_roads][quest->path_len + 1]
                = quest->path_len;
        quest->dists[quest->num_roads] = quest->path_dist;
        quest->num_roads += 1; // Переходим на следующий подмассив для записи
                               // следующего пути
        quest->number += 1; // Увеличиваем количество найденных путей на 1
    } else {
        // Идём по всем смежным вершинам
        for (int i = 0; i < graph->matrix_size; i++) {
            if (graph->matrix[start][i]
                && !quest->checked[i]) { // При условии, что дорога существует
                                         // и не пройдена
                quest->path_dist
                        += graph->matrix[start][i]; // Увеличиваем длину пути на
                                                    // вес ребра
                quest_roads(i, end, graph, target, quest);
                quest->path_dist
                        -= graph->matrix[start][i]; // Возвращаем длину пути к
                                                    // исходному значению
            }
        }
    }

    // Очищаем текущий путь и отмечаем вершину как не посещенную
    quest->path_len -= 1;
    quest->checked[start] = 0;
}

// Стартовая функция для создания временной структуры tackle и её последующей
// очистки
Roads* which_longer(int start, int end, Matrix* graph, Roads* target)
{
    tackle* quest = (tackle*)malloc(sizeof(tackle));
    ;
    quest->all_roads = prepare_two_dim_arr(quest->all_roads);
    quest->path_len = 0;
    quest->num_roads = 0;
    quest->path_dist = 0;
    quest->number = 0;
    quest->checked = (int*)calloc(MAX_SIZE, sizeof(int));
    if (!quest->checked) {
        free(quest->checked);
        return NULL;
    }
    quest->dists = (int*)calloc(MAX_SIZE, sizeof(int));
    if (!quest->dists) {
        free(quest->dists);
        return NULL;
    }
    quest->path = (int*)calloc(MAX_SIZE, sizeof(int));
    if (!quest->path) {
        free(quest->path);
        return NULL;
    }
    quest_roads(start, end, graph, target, quest);

    int max = 0;
    for (int i = 0; i < quest->number; i++) {
        if (target->path_dist < quest->dists[i]) {
            target->path_dist = quest->dists[i];
            max = i;
        }
    }

    int i = 0;
    while (quest->all_roads[max][i] != -1) {
        i++;
    }
    quest->path_len = i + 1;

    for (int j = 0; j < quest->path_len; j++) {
        target->path[j] = quest->all_roads[max][j];
    }

    free(quest->checked);
    free(quest->path);
    for (int i = 0; i < quest->number; i++) {
        free(quest->all_roads[i]);
    }
    free(quest);
    return target;
}