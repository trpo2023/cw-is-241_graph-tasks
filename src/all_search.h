#include <stdio.h>

typedef struct matrix Matrix;

typedef struct tools {
    int* checked; // Массив для отслеживания посещенных вершин
    int* path;    // Текущий путь
    int path_len; // Длина текущего пути
    int num_paths; // Номер текущего подмассива в двумерном массиве, сохраняющем
                   // все пути
} Tools;

typedef struct paths {
    int** all_paths; // Двумерный массив для хранения всех путей
    int number; // Переменная для подсчёта количества путей
} Paths;

void paths_search(int start, int end, Matrix* graph, Paths* aim, Tools* search);
Paths* how_many_paths(int start, int end, Matrix* graph, Paths* aim);
