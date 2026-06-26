#include <stdio.h>

void main(void) 
{ 
    float PRO;
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &PRO);
    if (PRO >= 7.0)
    {
        printf("El alumno esta aprobado");
    }
}