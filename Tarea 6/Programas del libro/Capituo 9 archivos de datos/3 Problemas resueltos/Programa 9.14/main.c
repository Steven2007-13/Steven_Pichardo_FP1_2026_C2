#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void minymay(FILE *);                  

void main(void)
{
    FILE *ar;
    
    ar = fopen("c:\\temp\\arc5.txt", "r");
    if (ar != NULL)
    {
        minymay(ar);    
        fclose(ar);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }
}

void minymay(FILE *arc)
{
    int min = 0, may = 0;
    char p;
    
    p = fgetc(arc);
    while (!feof(arc))
    {   
        if (islower(p))
        {
            min++; 
        }
        else if (isupper(p))
        {
            may++;
        }
        p = fgetc(arc);
    }
    printf("\nNumero de minusculas: %d", min);
    printf("\nNumero de mayusculas: %d\n", may);
}