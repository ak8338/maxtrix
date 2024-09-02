#include <stdio.h>

#define ROWS 2
#define COLS 2

// Function to multiply two matrices using array indices
void multiply_matrices_indices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to multiply two matrices using pointer arithmetic
void multiply_matrices_pointers(int *a, int *b, int *result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i*cols + j) = 0;
            for (int k = 0; k < cols; k++) {
                *(result + i*cols + j) += *(a + i*cols + k) * *(b + k*cols + j);
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2}, {3, 4}};
    int matrix2[ROWS][COLS] = {{5, 6}, {7, 8}};
    int result1[ROWS][COLS];
    int result2[ROWS][COLS];

    // Call the function to multiply matrices using array indices
    multiply_matrices_indices(matrix1, matrix2, result1);

    // Call the function to multiply matrices using pointer arithmetic
    multiply_matrices_pointers(&matrix1[0][0], &matrix2[0][0], &result2[0][0], ROWS, COLS);

    printf("Matrix 1:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix Multiplication using array indices:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix Multiplication using pointer arithmetic:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result2[i][j]);
        }
        printf("\n");
    }

    return 0;
}