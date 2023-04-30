#include <stdio.h>
#include <stdlib.h>

#include "all_search.h"
#include "input.h"

int main()
{
    char filename[100];
    printf("Введите имя файла: ");
    scanf("%s", filename);

    Matrix* graph = (Matrix*)malloc(sizeof(Matrix));

    graph->matrix = prepare_two_dim_arr(graph->matrix);
    graph->matrix_size = 0;

    read_matrix(filename, graph);

    // Вывод матрицы
    printf("Матрица:\n");
    for (int i = 0; i < graph->matrix_size; i++) {
        for (int j = 0; j < graph->matrix_size; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }

    int start, end;
    char choice;
    printf("Введите начальную и конечную вершину и выберите задачу из "
           "списка:\n");
    printf("1)Количество различных путей между городами\n2)Кратчайший путь "
           "между городами\n3)Длиннейший путь между городами\n");
    scanf("%d %d %c", &start, &end, &choice);

    switch (choice) {
    case '1':;
        Paths* aim = (Paths*)malloc(sizeof(Paths));
        aim->all_paths = prepare_two_dim_arr(aim->all_paths);
        aim->number = 0;
        // Запускаем поиск путей
        aim = how_many_paths(start, end, graph, aim);

        // Проверяем результат работы функций
        printf("Найдено %d пути(ей):\n", aim->number);
        for (int i = 0; i < aim->number; i++) {
            printf("%d. ", i + 1);
            int j = 0;
            for (j = 0; j < MAX_SIZE && aim->all_paths[i][j + 1] != -1; j++) {
                printf("%d -> ", aim->all_paths[i][j]);
            }
            printf("%d", aim->all_paths[i][j]);
            printf("\n");
        }
        break;
    case '2':
        printf("Эта задача временно недоступна\n");
        exit(1);
    case '3':
        printf("Эта задача временно недоступна\n");
        exit(1);
    default:
        printf("Выбранный номер задачи находится вне диапазона\n");
        exit(1);
    }

    for (int i = 0; i < graph->matrix_size; i++) {
        free(graph->matrix[i]);
    }
    free(graph);

    return 0;
}