#include <stdio.h>
#include <stdlib.h>
#define MATRIX_SIZE 5
#define SIZE 100

typedef struct tools {
    int* checked; // Массив для отслеживания посещенных вершин
    int* path;    // Текущий путь
    int path_len; // Длина текущего пути
    int num_paths; // Номер текущего подмассива в двумерном массиве, сохраняющем
                   // все пути
} Tools;

typedef struct paths {
    int all_paths[SIZE][SIZE]; // Двумерный массив для хранения всех путей
    int number; // Переменная для подсчёта количества путей
} Paths;

void paths_search(
        int start,
        int end,
        int graph[][MATRIX_SIZE],
        Paths* aim,
        Tools* search);
Paths* how_many_paths(int start, int end, int graph[][MATRIX_SIZE], Paths* aim);
Paths* new_path(int size);

int main()
{
    // Матрица
    int graph[MATRIX_SIZE][MATRIX_SIZE]
            = {{0, 5, 0, 4, 6},
               {5, 0, 3, 0, 0},
               {0, 3, 0, 6, 10},
               {4, 0, 6, 0, 5},
               {6, 0, 10, 5, 0}};
    int start, end;
    printf("Введите начальную и конечную вершину: ");
    scanf("%d %d", &start, &end);

    Paths* aim;
    aim = new_path(SIZE);
    // Запускаем поиск путей
    aim = how_many_paths(start, end, graph, aim);

    // Проверяем результат работы функций
    printf("Найдено %d пути(ей):\n", aim->number);
    for (int i = 0; i < aim->number; i++) {
        printf("%d. ", i + 1);
        int j = 0;
        for (j = 0; j < SIZE && aim->all_paths[i][j + 1] != -1; j++) {
            printf("%d -> ", aim->all_paths[i][j]);
        }
        printf("%d", aim->all_paths[i][j]);
        printf("\n");
    }

    return 0;
}

// Функция для выделения памяти под структуру типа Paths
Paths* new_path(int size)
{
    Paths* aim = (Paths*)malloc(sizeof(Paths));

    if (!aim) {
        free(aim);
        return NULL;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            aim->all_paths[i][j] = 0;
        }
    }
    aim->number = 0;
    return aim;
}

// Рекурсивная функция для обхода графа в глубину и нахождения всех путей
void paths_search(
        int start, int end, int graph[][MATRIX_SIZE], Paths* aim, Tools* search)
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
        for (int i = 0; i < MATRIX_SIZE; i++) {
            if (graph[start][i]
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
Paths* how_many_paths(int start, int end, int graph[][MATRIX_SIZE], Paths* aim)
{
    Tools search;
    search.path_len = 0;
    search.num_paths = 0;
    search.checked = (int*)calloc(SIZE, sizeof(int));
    if (!search.checked) {
        free(search.checked);
        return NULL;
    }
    search.path = (int*)calloc(SIZE, sizeof(int));
    if (!search.path) {
        free(search.path);
        return NULL;
    }
    paths_search(start, end, graph, aim, &search);
    free(search.checked);
    free(search.path);
    return aim;
}