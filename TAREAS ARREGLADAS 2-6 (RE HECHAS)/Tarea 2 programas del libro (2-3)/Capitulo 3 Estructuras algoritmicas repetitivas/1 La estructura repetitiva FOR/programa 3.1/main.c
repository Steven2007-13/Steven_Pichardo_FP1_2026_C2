#include <stdio.h>

void main(void)
{
    int I;
    float SAL, NOM;
    NOM = 0;
    for (I = 1; I <= 15; I++)
    {
        printf("Ingrese el salario del porfesor:\t", I);
        scanf("%f", &SAL);
        NOM = NOM + SAL;
    }
    printf("La nomina total es: %.2f\n", NOM);
}