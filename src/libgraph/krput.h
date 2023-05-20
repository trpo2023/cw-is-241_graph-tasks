#include <stdio.h>

typedef struct matrix Matrix;

typedef struct clover {
    int* ver; //  Массив пути
    int k;    // Вес массива
    int ves;  // Длинна пути
} Clover;

Clover* krPut(Matrix* graph, int start, int end, Clover* kr);
