#include <stdio.h>

void rango(int);

int RA1 = 0, RA2 = 0, RA3 = 0, RA4 = 0, RA5 = 0;

void main(void)
{
    float CAL;
    printf("\nIngresa la primera calificacion del alumno: ");
    scanf("%f", &CAL);
    while (CAL != -1)
    {
        rango(CAL);
        printf("\nIngresa la calificacion del siguiente alumno: ");
        scanf("%f", &CAL);
    }
    printf("\n0..3.99 = %d", RA1);
    printf("\n4..5.99 = %d", RA2);
    printf("\n6..7.99 = %d", RA3);
    printf("\n8..8.99 = %d", RA4);
    printf("\n9..10 = %d", RA5);
}

void rango(int VAL)
{
    if(VAL < 4)
    {
        RA1++;
    }
    else if (VAL < 6)
    {
        RA2++;
    }
    else if (VAL < 8)
    {
        RA3++;
    }
    else if (VAL < 9)
    {
        RA4++;
    }
    else
    {
        RA5++;
    }
}