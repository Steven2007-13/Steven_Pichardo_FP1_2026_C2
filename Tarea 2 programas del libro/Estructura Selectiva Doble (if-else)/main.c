#include <stdio.h>
#include <stdlib.h>

int main()
{
    float promedio; //punto flotante para el promedio del estudiante
    int valido; //variable para evitar bugs
    printf("--- Control de Aprobados ---\n");
    printf("Ingrese el promedio del estudiante (de 0 a 10): ");
    valido = scanf("%f", &promedio); //aseguramos que se inserte un digito numerico y se le asigna a promedio
    while(getchar() !='\n'); //limpiamos el buffer en caso de que no sea asi
    if  (valido == 1 && promedio >= 0.0 && promedio <= 10.0) //declaramos los margenes de 0 a 10 y que sean digitos numericos
    {
        if (promedio >= 7.0)//declaramos el limite para ser aprobados en este caso 7
        {
            printf("\n\nFelicidades has aprobado!\n");
        }else {printf("\n\nReprobado, mejor suerte la proxima!\n");}
    }else {printf("\n\nError: El promedio ingrasado no es valido");}//mensaje de error
    return 0;
}
