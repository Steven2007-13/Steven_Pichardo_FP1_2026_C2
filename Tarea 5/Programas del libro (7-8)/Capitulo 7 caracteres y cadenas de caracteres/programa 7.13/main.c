#include <stdio.h>

int cuenta(char *);

void main(void)
{
    int i;
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Quitar el salto de línea que agrega fgets
    for (int j = 0; cad[j] != '\0'; j++)
    {
        if (cad[j] == '\n')
        {
            cad[j] = '\0';
            break;
        }
    }

    i = cuenta(cad);

    printf("\nLongitud de la cadena: %d\n", i);
}

int cuenta(char *cadena)
{
    int c = 0;
    
    while (cadena[c] != '\0')
    {
        c++;
    }
    
    return (c);
}