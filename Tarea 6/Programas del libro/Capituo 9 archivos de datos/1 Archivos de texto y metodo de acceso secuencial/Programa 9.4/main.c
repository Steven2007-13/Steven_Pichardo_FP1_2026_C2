#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char cad[50];
    FILE *ap;
    
    ap = fopen("c:\\temp\\arc.txt", "r");
    if (ap != NULL) 
    {
        while (fgets(cad, 50, ap) != NULL) 
        {
            printf("%s", cad);
        }
        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }
}