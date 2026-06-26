#include <stdio.h>
#include <ctype.h>
#include <string.h>

void minymay(char *cadena);

void main(void)
{
    int i, n;
    char FRA[20][50];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);

    while (getchar() != '\n');

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la linea %d de texto: ", i+1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Quitar el salto de linea que agrega fgets
        for (int j = 0; FRA[i][j] != '\0'; j++)
        {
            if (FRA[i][j] == '\n')
            {
                FRA[i][j] = '\0';
                break;
            }
        }
    }

    printf("\n\n");

    for (i = 0; i < n; i++)
    {
        minymay(FRA[i]);
    }
}

void minymay(char *cadena)
{
    int i = 0, mi = 0, ma = 0;

    while(cadena[i] != '\0')
    {
        if (islower(cadena[i]))
        {
            mi++;
        }
        else if (isupper(cadena[i]))
        {
            ma++;
        }
        i++;
    }

    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d", ma);
}