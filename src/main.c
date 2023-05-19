#include <stdio.h>
#include <stdlib.h>

#include "all_search.h"
#include "input.h"
#include "krput.h"
#include "long_quest.h"
#include "output.h"

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
        aim = how_many_paths(start - 1, end - 1, graph, aim);
        // Выводим результат работы функций
        output(choice, aim, NULL, NULL);
        break;
    case '2':;
        Clover* kr = (Clover*)malloc(sizeof(Clover));
        kr->ver = (int*)calloc(graph->matrix_size, sizeof(int));
        if (!kr->ver) {
            free(kr->ver);
        }
        kr->k = 1;
        kr->ves = 0;
        //Запускаем поиск кратчайшего пути
        kr = krPut(graph, start, end, kr);
        //Вывод рузультат работы функции
        output(choice, NULL, kr, NULL);
        break;
    case '3':;
        Roads* target = (Roads*)malloc(sizeof(Roads));
        target->path = malloc(MAX_SIZE * sizeof(int));
        target->path_dist = 0;
        // Запускаем поиск путей
        target = which_longer(start - 1, end - 1, graph, target);
        // Вывод результат работы функций
        output(choice, NULL, NULL, target);
        break;
    default:
        printf("Выбранный номер задачи находится вне диапазона\n");
        break;
    }

    for (int i = 0; i < graph->matrix_size; i++) {
        free(graph->matrix[i]);
    }
    free(graph);

    return 0;
}