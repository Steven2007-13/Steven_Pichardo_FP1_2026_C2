#include <stdio.h>
#include <stdlib.h>

#define TAM 100

/* Búsqueda en un vector.
El programa, al recibir como datos un arreglo unidimensional de tipo entero
y un número entero, determina cuántas veces se encuentra dicho número en el arreglo. */

int main()
{
    int ARREGLO[TAM];
    int I;
    int N = 0;
    int NUM = 0;
    int CONTA = 0;;

    printf("--- PROGRAMA 5.1: BUSQUEDA EN VECTOR ---\n\n");

    /* Validamos que el usuario no pida más del tamaño máximo */
    do {
        printf("Ingrese el numero de elementos que va a registrar (1 a 100): ");
        scanf("%d", &N);
        while(getchar() !='\n');
    } while (N > TAM || N < 1);

    /* Ciclo para llenar el vector */
    for (I = 0; I < N; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &ARREGLO[I]);
        while(getchar() !='\n');
    }

    printf("\n¿Cual es el numero que desea buscar en el vector?: ");
    scanf("%d", &NUM);
    while(getchar() !='\n')

    /* Ciclo para recorrer el vector y contar las coincidencias */
    for (I = 0; I < N; I++)
    {
        if (ARREGLO[I] == NUM)
        {
            CONTA++;
        }
    }

    printf("\nEl numero %d se encuentra %d veces en el arreglo.\n", NUM, CONTA);

    return 0;
}
