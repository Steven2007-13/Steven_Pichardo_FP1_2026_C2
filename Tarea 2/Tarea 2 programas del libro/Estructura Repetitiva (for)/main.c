#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, numero, suma = 0; //declaramos multiples variables separadas por comas
    printf("--- Sumador de 5 numeros ---\n");
    for (i = 1; i <= 5; i++)
    {
        printf("\nIngresa el numero %i: ", i);
        scanf("%i", &numero);
        while(getchar() !='\n');
        suma += numero;//acumula el valor
    }
    printf("\nLa suma total de los numeros ingresados es: %i\n", suma);
    return 0;
}
