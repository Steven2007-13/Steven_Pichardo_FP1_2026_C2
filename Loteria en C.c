#include <stdio.h>
#include <stdlib.h>
#define PRIMERA 67
#define SEGUNDA 47
#define TERCERA 69
#define JUGAR 1
#define SALIR 0
int main()
{
    int numero = 0;
    int menu = -1;
    int valido = 0;
    do
    {
    printf("\n\nLoteria\n");
    printf("\n0-Salir\n1-Jugar\n\n");
    scanf("%i",&menu);
    while(getchar() != '\n');
    if (menu !=1)
    {
        printf("\nEntonces no quieres jugar?\n");
        while(getchar()!='\n');
        continue;
    }
    else if (menu == 1)
    {
       printf("\nIngresa el numero a jugar: (de 1 a 99)\n\n");
       valido = scanf("%i",&numero);
       while(getchar() != '\n');
    }
    if(valido == 1 && numero > 0 && numero <= 99)
     {
         if(numero == PRIMERA)
         {
             printf("\nGanaste el primer lugar!\n");
         }
         else if(numero == SEGUNDA)
         {
             printf("\nGanaste el segundo lugar!\n");
         }
         else if(numero == TERCERA)
         {
             printf("\nGanaste el tercer lugar!\n");
         }
         else
         {
             printf("\nPerdiste\n");
         }
     }else
     {
         printf("\nDato ingresado no valido\n");
         while(getchar() != '\n');
     }
    printf("\nQuieres jugar de nuevo? (presione 0 para salir, de lo contraio inserte cualquier caracter)\n\n");
    scanf("%i",&menu);
    while(getchar() != '\n');
    }while (menu != SALIR);
    return 0;
}
