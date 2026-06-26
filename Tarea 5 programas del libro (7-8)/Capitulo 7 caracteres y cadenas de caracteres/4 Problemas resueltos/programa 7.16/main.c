#include <stdio.h>
#include <string.h>

void main(void)
{
    char cad1[50], cad2[50];
    char *cad0;
    int i = 0;

    printf("\nIngrese la primera cadena de caracteres: ");
    fgets(cad1, sizeof(cad1), stdin);

    // Quitar el salto de línea de cad1
    for (int j = 0; cad1[j] != '\0'; j++)
    {
        if (cad1[j] == '\n')
        {
            cad1[j] = '\0';
            break;
        }
    }

    printf("\nIngrese la cadena a buscar: ");
    fgets(cad2, sizeof(cad2), stdin);

    // Quitar el salto de línea de cad2
    for (int j = 0; j < cad2[j] != '\0'; j++)
    {
        if (cad2[j] == '\n')
        {
            cad2[j] = '\0';
            break;
        }
    }
    cad0 = cad1;

    cad0 = strstr(cad0, cad2);

    while(cad0 != NULL)
    {
        i++;
        cad0 = strstr(cad0 + 1, cad2);
    }

    printf("\nEl numero de veces que aparece la segunda cadena es: %d\n", i);
}