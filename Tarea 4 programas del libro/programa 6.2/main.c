#include <stdio.h>
#include <stdlib.h>

/* Suma de matrices.
El programa lee dos matrices del mismo tamaño, las suma y muestra el resultado. */

#define MAX 10

/* Prototipos de funciones */
void LecturaMatriz(int A[][MAX], int F, int K);
void SumaMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int F, int K);
void ImprimeMatriz(int A[][MAX], int F, int K);

int main()
{
    int MAT1[MAX][MAX], MAT2[MAX][MAX], MAT3[MAX][MAX];
    int FILAS = 0, COLUMNAS = 0;

    printf("--- PROGRAMA 6.2: SUMA DE MATRICES ---\n\n");

    printf("Ingrese numero de filas (Max 10): ");
    scanf("%d", &FILAS);
    while(getchar()!='\n');
    printf("Ingrese numero de columnas (Max 10): ");
    scanf("%d", &COLUMNAS);
    while(getchar()!='\n');
    printf("\n--- LECTURA DE LA MATRIZ 1 ---\n");
    LecturaMatriz(MAT1, FILAS, COLUMNAS);

    printf("\n--- LECTURA DE LA MATRIZ 2 ---\n");
    LecturaMatriz(MAT2, FILAS, COLUMNAS);

    /* Hacemos la suma */
    SumaMatrices(MAT1, MAT2, MAT3, FILAS, COLUMNAS);

    printf("\n--- MATRIZ RESULTANTE (SUMA) ---\n");
    ImprimeMatriz(MAT3, FILAS, COLUMNAS);

    return 0;
}

void LecturaMatriz(int A[][MAX], int F, int K)
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < K; J++)
        {
            printf("Elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
            while(getchar() !='\n');
        }
    }
}

void SumaMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int F, int K)
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < K; J++)
        {
            /* Suma matemática de la posición actual */
            C[I][J] = A[I][J] + B[I][J];
        }
    }
}

void ImprimeMatriz(int A[][MAX], int F, int K)
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < K; J++)
        {
            printf("%d\t", A[I][J]); /* El \\t investigue que lo puedo usar para dar espacio de tabla como un tab */
        }
        printf("\n"); /* Salto de línea al terminar cada fila */
    }
}
