// VAR 7

#include "4p.h"

#define SIZE 6

void matrix_init(int *matrix, int size) {
    int value = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(matrix + i * size + j) = value++;
        }
    }
}

void matrix_transpose(int *matrix, int *transposed, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(transposed + j * size + i) = *(matrix + i * size + j);
        }
    }
}

void matrix_print(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d", *(matrix + i * size + j));
        }
        printf("\n");
    }
}

int main() {

    int matrix_original[SIZE][SIZE];
    int matrix_transposed[SIZE][SIZE];

    matrix_init((int *)matrix_original, SIZE);

    printf("\nOriginal Matrix:\n");
    matrix_print((int *)matrix_original, SIZE);

    matrix_transpose((int *)matrix_original, (int *)matrix_transposed, SIZE);

    printf("\nTransposed Matrix:\n");
    matrix_print((int *)matrix_transposed, SIZE);

    return 0;
}
