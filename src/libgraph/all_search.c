#include <stdio.h>
#include <stdlib.h>

#include <libgraph/all_search.h>
#include <libgraph/input.h>

// Рекурсивная функция для обхода графа в глубину и нахождения всех путей
void paths_search(int start, int end, Matrix* graph, Paths* aim, Tools* search)
{
    search->checked[start] = 1;
    search->path[search->path_len] = start;
    search->path_len += 1;

    if (start == end) {
        // Записываем найденный путь в исходную структуру
        for (int i = 0; i < search->path_len; i++) {
            aim->all_paths[search->num_paths][i] = search->path[i];
        }
        aim->all_paths[search->num_paths][search->path_len] = -1;
        search->num_paths += 1; // Переходим на следующий подмассив для записи
                                // следующего пути
        aim->number += 1; // Увеличиваем количество найденных путей на 1
    } else {
        // Идём по всем смежным вершинам
        for (int i = 0; i < graph->matrix_size; i++) {
            if (graph->matrix[start][i]
                && !search->checked[i]) { // При условии, что дорога существует
                                          // и не пройдена
                paths_search(i, end, graph, aim, search);
            }
        }
    }

    // Очищаем текущий путь и отмечаем вершину как не посещенную
    search->path_len -= 1;
    search->checked[start] = 0;
}

// Стартовая функция для создания временной структуры Tools и её последующей
// очистки
Paths* how_many_paths(int start, int end, Matrix* graph, Paths* aim)
{
    Tools search;
    search.path_len = 0;
    search.num_paths = 0;
    search.checked = (int*)calloc(MAX_SIZE, sizeof(int));
    if (!search.checked) {
        free(search.checked);
        return NULL;
    }
    search.path = (int*)calloc(MAX_SIZE, sizeof(int));
    if (!search.path) {
        free(search.path);
        return NULL;
    }
    paths_search(start, end, graph, aim, &search);
    free(search.checked);
    free(search.path);
    return aim;
}