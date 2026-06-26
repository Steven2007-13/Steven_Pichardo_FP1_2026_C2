#include <stdio.h>

void Mayor(float,float,float);

void main(void)
{
    int I;
    float GOL, PAC, CAR, AGOL = 0, APAC = 0, ACAR = 0;
    for (I = 1; I <= 12; I++)
    {
        printf("\n\nIngresa las lluvias del mes %d\t", I);
        printf("Regiones Golfo, Pacifico y Caribe :");
        scanf("%f %f %f", &GOL, &PAC, &CAR);
        AGOL += GOL;
        APAC += PAC;
        ACAR += CAR;
    }
    printf("\n\nPromedio de lluvias region golfo: %6.2f", (AGOL / 12));
    printf("\n\nPromedio de lluvias region pacifico: %6.2f", (APAC / 12));
    printf("\n\nPromedio de lluvias region caribe: %6.2f \n", (ACAR / 12));
    Mayor(AGOL, APAC, ACAR);
}

void Mayor(float R1, float R2, float R3)
{
    if (R1 > R2)
    {
        if (R1 > R3)
        {
            printf ("\nRegion con mayor pormedio: Region golfo. Promedio: %6.2f", (R1 / 12));
        }
        else
        {
            printf ("\nRegion con mayor pormedio: Region caribe. Promedio: %6.2f", (R3 / 12));
        }
    }
    else if (R2 > R3)
    {
        printf ("\nRegion con mayor pormedio: Region pacifico. Promedio: %6.2f", (R2 / 12));
    }
    else
    {
        printf ("\nRegion con mayor pormedio: Region caribe. Promedio: %6.2f", (R3 / 12));
    }
}