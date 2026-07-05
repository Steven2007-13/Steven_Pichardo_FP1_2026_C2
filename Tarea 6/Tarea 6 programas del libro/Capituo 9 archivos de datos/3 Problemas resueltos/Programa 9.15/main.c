#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void minymay(FILE *);             

void main(void)
{
    FILE *ap;
    
    ap = fopen("c:\\temp\\arc.txt", "r");
    if (ap != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }
}

void minymay(FILE *ap1)
{
    char cad[30];
    int i, mi = 0, ma = 0; 
    
    fgets(cad, 30, ap1);
    while (!feof(ap1))
    {  
        i = 0;
        while (cad[i] != '\0')
        {  
            if (islower(cad[i]))
            {
                mi++;
            }
            else if (isupper(cad[i]))
            {
                ma++;
            }
            i++;
        }
        fgets(cad, 30, ap1);
    }
    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d\n", ma);
}