#include <stdio.h>
#include <string.h>

int cuentap(char *);

void main(void)
{
    int i;
    char fra[100]; 

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

    strcat(fra, " "); 

    i = cuentap(fra);

    printf("\nLa linea de texto tiene %d palabras\n", i);
}

int cuentap(char *cad)
{
    char *cad0;
    int i = 0;
    
    cad0 = strstr(cad, " "); 

    while(cad0 != NULL && cad[0] != '\0')
    {
        i++;
        cad = cad0 + 1;
        cad0 = strstr(cad, " ");
    }

    return(i);
}