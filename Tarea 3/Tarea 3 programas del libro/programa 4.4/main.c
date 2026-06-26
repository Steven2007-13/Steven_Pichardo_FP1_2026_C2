#include <stdio.h>
#include <stdlib.h>

/* Prueba de variables globales, locales y estáticas.
El programa utiliza funciones en las que se usan diferentes tipos de variables. */

/* Prototipos de funciones */
int f1(void);
int f2(void);
int f3(void);

/* Variable global */
int K = 3;

int main()
{
    int I;

    printf("--- PROGRAMA 4.4: TIPOS DE VARIABLES ---\n");

    /* El bucle se repite 3 veces para ver cómo cambian los valores */
    for (I = 1; I <= 3; I++)
    {
        printf("\n--- REPETICION %d ---", I);
        printf("\nEl resultado de la funcion f1 (Global)   es: %d", f1());
        printf("\nEl resultado de la funcion f2 (Local)    es: %d", f2());
        printf("\nEl resultado de la funcion f3 (Estatica) es: %d\n", f3());
    }

    printf("\n");
    return 0;
}

/* La función f1 utiliza y modifica la variable global K */
int f1(void)
{
    K += K;
    return (K);
}

/* La función f2 utiliza una variable local K */
int f2(void)
{
    int K = 1;
    K++;
    return (K); /* Siempre va a regresar 2 porque se destruye y recrea */
}

/* La función f3 utiliza una variable estática K */
int f3(void)
{
    /* Se inicializa en 8 SOLO la primera vez */
    static int K = 8;
    K += 2;
    return (K); /* No olvida su valor; sumará de 2 en 2 en cada iteración */
}
