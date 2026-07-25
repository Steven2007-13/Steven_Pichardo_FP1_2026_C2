#include <stdio.h>

void inverso(char *);

void main(void)
{
    char fra[50];

    printf("\nIngrese la linea de texto: ");
    fgets(fra, sizeof(fra), stdin);

    // Quitar el salto de línea que agrega fgets
    for (int j = 0; fra[j] != '\0'; j++)
    {
        if (fra[j] == '\n')
        {
            fra[j] = '\0';
            break;
        }
    }

    printf("\nEscribe la linea de texto en forma inversa: ");
    inverso(fra);
    printf("\n");
}

void inverso(char *cadena)
{
    if(cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}