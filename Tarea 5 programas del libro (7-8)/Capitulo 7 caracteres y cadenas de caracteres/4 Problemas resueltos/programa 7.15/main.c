#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void interpreta(char *);

void main(void)
{
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Quitamos el salto de línea que añade fgets
    for (int j = 0; cad[j] != '\0'; j++)
    {
        if (cad[j] == '\n')
        {
            cad[j] = '\0';
            break;
        }
    }

    interpreta(cad);
    printf("\n");
}

void interpreta(char *cadena)
{
    int i = 0, j, k;

    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i]))
        {
            k = cadena[i - 1] - 48;

            for (j = 0; j < k; j++)
            {
                putchar(cadena[i]);
            }
        }
        i++;
    }
}