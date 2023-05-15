#include <stdio.h>

typedef struct matrix Matrix;

typedef struct tackle {
    int* checked; // Массив для отслеживания посещенных вершин
    int* path;    // Текущий путь
    int path_len; // Длина текущего пути
    int path_dist;
    int num_roads; // Номер текущего подмассива в двумерном массиве, сохраняющем
                   // все пути
    int number;    // Количество путей
    int** all_roads; // Двумерный массив для хранения всех путей
    int* dists; // Длины путей
} tackle;

typedef struct path {
    int* path;     // Длиннейший путь
    int path_dist; // Длина пути
} Roads;

void quest_roads(
        int start, int end, Matrix* graph, Roads* target, tackle* quest);
Roads* which_longer(int start, int end, Matrix* graph, Roads* aim);
Roads* new_path(int size);
