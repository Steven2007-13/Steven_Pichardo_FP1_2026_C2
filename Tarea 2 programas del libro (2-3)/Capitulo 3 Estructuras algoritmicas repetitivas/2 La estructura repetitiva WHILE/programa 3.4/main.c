#include <stdio.h>
#include <math.h>

void main (void)
{
    int NUM;
    long CUA, SUC = 0;
    printf("Ingrese un numero entero -0 para terminar:\t");
    scanf("%d", &NUM);
    while (NUM)
    {
        CUA = pow(NUM, 2);
        printf("El cuadrado de %d es %ld\n", NUM, CUA);
        SUC += CUA;
        printf("Ingrese un numero entero -0 para terminar:\t");
        scanf("%d", &NUM);
    }
    printf("\nLa suma de los cuadrados es: %ld", SUC);
}