#include <stdio.h>
#include <stdlib.h>

#define TAM 10

/* Prototipo de funciones */
void Lectura(int A[][TAM], int F);
void Imprime(int A[][TAM], int F);

int main()
{
    int MAT[TAM][TAM];
    int FILAS;

    printf("--- PROGRAMA 6.1: DIAGONAL PRINCIPAL ---\n\n");

    do {
        printf("Ingrese el tamaño de la matriz cuadrada (Maximo 10): ");
        scanf("%d", &FILAS);
        while(getchar() !='\n');
    } while (FILAS > TAM || FILAS < 1);

    Lectura(MAT, FILAS);
    Imprime(MAT, FILAS);

    return 0;
}

/* Función para leer los elementos de la matriz cuadrada */
void Lectura(int A[][TAM], int F)
{
    int I, J;
    for(I = 0; I < F; I++)
    {
        for(J = 0; J < F; J++)
        {
            printf("Ingrese el elemento de la fila %d, columna %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
            while(getchar() !='\n');
        }
    }
}

/* Función para buscar e imprimir la diagonal principal */
void Imprime(int A[][TAM], int F)
{
    int I, J;
    printf("\n--- ELEMENTOS DE LA DIAGONAL PRINCIPAL ---");
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < F; J++)
        {
            if (I == J) /* Si la fila es igual a la columna, es diagonal */
            {
                printf("\nDiagonal [%d][%d]: %d", I, J, A[I][J]);
            }
        }
    }
}
