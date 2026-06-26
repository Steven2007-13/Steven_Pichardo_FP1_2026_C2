#include <stdio.h>
#include <ctype.h>

void main(void)
{
    char p, cad[50];
    int n;

    printf("\nIngrese la cadena de caracteres (maximo 50): ");
    fgets(cad, sizeof(cad), stdin);

    printf("\nIngrese la posicion en la cadena que desea verificar: ");
    scanf("%d", &n);

    if ((n >= 1) && (n <= 50))
    {
        // El arreglo en C empieza en el índice 0, por eso se usa n-1.
        p = cad[n - 1];
        
        if (p != '\n' && p != '\0')
        {
            if (islower(p))
            {
                printf("\n%c es una letra minuscula\n", p);
            }
            else
            {
                printf("\n%c no es una letra minuscula\n", p);
            }
        }
        else
        {
            printf("\nLa posicion ingresada esta fuera del texto ingresado o esta vacia.\n");
        }
    }
    else
    {
        printf("\nEl valor ingresado de n es incorrecto\n");
    }
}