#include <stdio.h>

void main(void)
{
    int I = 0;
    float SAL, PRO, NOM = 0;
    printf("Ingrese el salario del profesor: ");
    scanf("%f", &SAL);
    do
    {
        NOM = NOM + SAL;
        I = I + 1;
        printf("Ingrese el salario del profesor -0 para terminar: ");
        scanf("%f", &SAL);
    }
    while (SAL);
    PRO = NOM / I;
    printf("\nNomina:%.2f\tPromedio de salarios: %.2f", NOM, PRO);
}