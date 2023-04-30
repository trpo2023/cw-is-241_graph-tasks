#define MAX_SIZE 100

typedef struct matrix {
    int** matrix; // Двумерный массив для хранения матрицы
    int matrix_size; // Размер матрицы
} Matrix;

int** prepare_two_dim_arr(int** arr);
void read_matrix(char* filename, Matrix* graph);