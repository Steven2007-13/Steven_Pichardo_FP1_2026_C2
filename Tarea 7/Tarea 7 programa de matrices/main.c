#include <stdio.h>
#include <stdlib.h>

// Declaración de funciones
double** allocateMatrix(int rows, int cols);
void freeMatrix(double** matrix, int rows);
void readMatrix(double** matrix, int rows, int cols, const char* name);
void multiplyMatrices(double** A, double** B, double** C, int r1, int c1, int c2);
void printMatrix(double** matrix, int rows, int cols);

int main() {
    int r1, c1, r2, c2;

    printf("=== Multiplicacion de Matrices ===\n\n");

    // Entrada de dimensiones para la Matriz A
    printf("Ingrese el numero de filas de la Matriz A: ");
    if (scanf("%d", &r1) != 1 || r1 <= 0) {
        printf("Error: Dimensiones invalidas.\n");
        return 1;
    }
    printf("Ingrese el numero de columnas de la Matriz A: ");
    if (scanf("%d", &c1) != 1 || c1 <= 0) {
        printf("Error: Dimensiones invalidas.\n");
        return 1;
    }

    // Entrada de dimensiones para la Matriz B
    printf("Ingrese el numero de filas de la Matriz B: ");
    if (scanf("%d", &r2) != 1 || r2 <= 0) {
        printf("Error: Dimensiones invalidas.\n");
        return 1;
    }
    printf("Ingrese el numero de columnas de la Matriz B: ");
    if (scanf("%d", &c2) != 1 || c2 <= 0) {
        printf("Error: Dimensiones invalidas.\n");
        return 1;
    }

    // Verificación de si la multiplicación es matemáticamente posible
    if (c1 != r2) {
        printf("\nError: No se pueden multiplicar las matrices.\n");
        printf("El numero de columnas de la Matriz A (%d) debe ser igual al numero de filas de la Matriz B (%d).\n", c1, r2);
        return 1;
    }

    // Reservar memoria dinámica para las matrices
    double** A = allocateMatrix(r1, c1);
    double** B = allocateMatrix(r2, c2);
    double** C = allocateMatrix(r1, c2);

    if (A == NULL || B == NULL || C == NULL) {
        printf("Error: Fallo en la asignacion dinamica de memoria.\n");
        freeMatrix(A, r1);
        freeMatrix(B, r2);
        freeMatrix(C, r1);
        return 1;
    }

    // Lectura de los elementos de las matrices
    printf("\n--- Lectura de la Matriz A (%dx%d) ---\n", r1, c1);
    readMatrix(A, r1, c1, "A");

    printf("\n--- Lectura de la Matriz B (%dx%d) ---\n", r2, c2);
    readMatrix(B, r2, c2, "B");

    // Realizar la multiplicación
    multiplyMatrices(A, B, C, r1, c1, c2);

    // Mostrar los resultados
    printf("\n--- Matriz A (%dx%d) ---\n", r1, c1);
    printMatrix(A, r1, c1);

    printf("\n--- Matriz B (%dx%d) ---\n", r2, c2);
    printMatrix(B, r2, c2);

    printf("\n--- Matriz Resultante C = A * B (%dx%d) ---\n", r1, c2);
    printMatrix(C, r1, c2);

    // Liberar la memoria asignada
    freeMatrix(A, r1);
    freeMatrix(B, r2);
    freeMatrix(C, r1);

    printf("\nPrograma finalizado con exito!\n");
    return 0;
}

// Función para asignar memoria dinámicamente a una matriz
double** allocateMatrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    if (matrix == NULL) return NULL;
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (matrix[i] == NULL) {
            // Liberar memoria ya asignada en caso de error a mitad de camino
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

// Función para liberar la memoria dinámica de una matriz
void freeMatrix(double** matrix, int rows) {
    if (matrix == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Función para leer los elementos de una matriz desde el teclado
void readMatrix(double** matrix, int rows, int cols, const char* name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Ingrese el elemento %s[%d][%d]: ", name, i + 1, j + 1);
            while (scanf("%lf", &matrix[i][j]) != 1) {
                printf("Entrada invalida. Ingrese un numero real para %s[%d][%d]: ", name, i + 1, j + 1);
                // Limpiar el búfer de entrada
                while (getchar() != '\n');
            }
        }
    }
}

// Función para multiplicar dos matrices (C = A * B)
void multiplyMatrices(double** A, double** B, double** C, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Función para imprimir una matriz con formato limpio
void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("[ ");
        for (int j = 0; j < cols; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("]\n");
    }
}