#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct matrix {
    int** matrix; // Двумерный массив для хранения матрицы
    int matrix_size; // Размер матрицы
} Matrix;

int** prepare_two_dim_arr(int** arr);
void read_matrix(char* filename, Matrix* graph);

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

    for (int i = 0; i < graph->matrix_size; i++) {
        free(graph->matrix[i]);
    }
    free(graph);

    return 0;
}

int** prepare_two_dim_arr(int** arr)
{
    arr = malloc(MAX_SIZE * sizeof(int*));
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = malloc(MAX_SIZE * sizeof(int));
    }

    return arr;
}

void read_matrix(char* filename, Matrix* graph)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }

    int row = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, " ");
        int col = 0;
        while (token != NULL) {
            graph->matrix[row][col] = atoi(token);
            token = strtok(NULL, " ");
            col++;
        }
        row++;
    }
    graph->matrix_size = row;

    fclose(file);
}