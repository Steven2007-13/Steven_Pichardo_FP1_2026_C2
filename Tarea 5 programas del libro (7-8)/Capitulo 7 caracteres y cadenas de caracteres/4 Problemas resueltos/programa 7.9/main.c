#include <stdio.h>

int cuenta(char *, char);

void main(void)
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    // Quitar el salto de línea que agrega fgets
    for (int i = 0; cad[i] != '\0'; i++)
    {
        if (cad[i] == '\n')
        {
            cad[i] = '\0';
            break;
        }
    }

    printf("\nIngrese el caracter: ");
    car = getchar();

    res = cuenta(cad, car);

    printf("\n\n%c se encuentra %d veces en la cadena %s\n", car, res, cad);
}

int cuenta(char *cad, char car)
{
    int i = 0, r = 0;

    while (cad[i] != '\0')
    {
        if (cad[i] == car)
        {
            r++;
        }
        i++;
    }

    return (r);
}