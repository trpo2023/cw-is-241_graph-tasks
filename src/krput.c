#include <stdio.h>
#include <stdlib.h>

#include "all_search.h"
#include "input.h"
#include "krput.h"

Clover* krPut(Matrix* graph, int start, int end, Clover* kr)
{
    end--;
    start--;
    int d[graph->matrix_size];
    int v[graph->matrix_size];
    int temp, minindex, min;
    // Вывод матрицы связей
    // for (int i = 0; i < graph->matrix_size; i++) {
    //     for (int j = 0; j < graph->matrix_size; j++) {
    //         printf("%5d ",  graph->matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    //Инициализация вершин и расстояний
    for (int i = 0; i < graph->matrix_size; i++) {
        d[i] = 10000;
        v[i] = 1;
    }
    d[start] = 0;
    // Шаг алгоритма
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < graph->matrix_size; i++) {
            if ((v[i] == 1) && (d[i] < min)) {
                min = d[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000) {
            for (int i = 0; i < graph->matrix_size; i++) {
                if (graph->matrix[minindex][i] > 0) {
                    temp = min + graph->matrix[minindex][i];
                    if (temp < d[i]) {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);
    // Восстановление пути

    kr->ver[0] = end + 1;
    kr->ves = d[end];
    int weight = d[end];
    while (end != start) {
        for (int i = 0; i < graph->matrix_size; i++) {
            if (graph->matrix[i][end] != 0) {
                int temp = weight - graph->matrix[i][end];
                if (temp == d[i]) {
                    weight = temp;
                    end = i;
                    kr->ver[kr->k] = i + 1;
                    kr->k++;
                }
            }
        }
    }
    //Реверс массива
    for (int i = kr->k - 1, j = 0; i > j; i--, j++) {
        int pust;
        pust = kr->ver[i];
        kr->ver[i] = kr->ver[j];
        kr->ver[j] = pust;
    }
    return kr;
}
