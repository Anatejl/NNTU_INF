// VAR 7

#include "4a.h"

void matrix_init(int matrix[SIZE][SIZE]) {
    int value = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = value++;
        }
    }
}

void matrix_transpose(int matrix[SIZE][SIZE], int transposed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void matrix_print(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int matrix_original[SIZE][SIZE];
    int matrix_transposed[SIZE][SIZE];

    matrix_init(matrix_original);

    printf("Original Matrix:\n");
    matrix_print(matrix_original);

    matrix_transpose(matrix_original, matrix_transposed);


    printf("\nTransposed Matrix:\n");
    matrix_print(matrix_transposed);

    return 0;
}