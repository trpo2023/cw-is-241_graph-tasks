#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgraph/input.h>

int** prepare_two_dim_arr(int** arr)
{
    arr = malloc(MAX_SIZE * sizeof(int*));
    if (!arr) {
        free(arr);
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = malloc(MAX_SIZE * sizeof(int));
        if (!arr[i]) {
            free(arr[i]);
        }
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

    char line[MAX_SIZE];
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