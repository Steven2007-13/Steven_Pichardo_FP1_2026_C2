#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;
    int suma = 0;
    printf("--- Sumador Continuo ---\n(introduce un numero negativo para terminar)\n\n");
    while (numero >= 0)
    {
        suma += numero;
        printf("Ingrese numero a sumar: ");
        scanf("%i", &numero);
        while(getchar() !='\n');
    }
    printf("\nCiclo terminado. La suma total es: %i", suma);
    return 0;
}
