#include <stdio.h>

void main(void)
{
    int I, N;
    float LAN, SLA = 0;
    do
    {
        printf("Ingrese el numero de lanzamientos: ");
        scanf("%d", &N);
    }
    while (N < 1 || N > 11);
    for (I = 1; I <= N; I++)
    {
        printf("\nIngrese el lanzamiento numero %d: ", I);
        scanf("%f", &LAN);
        SLA = SLA + LAN;
    }
    SLA = SLA / N;
    printf("\nEl promedio de los lanzamientos es: %.2f", SLA);
}