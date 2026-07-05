#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cambia(FILE *, FILE *);

void main(void)
{
    FILE *ar;
    FILE *ap;
    
    ar = fopen("c:\\temp\\arc.txt", "r");
    ap = fopen("c:\\temp\\arc1.txt", "w");
    
    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
    {
        printf("No se pueden abrir los archivos\n");
    }
}

void cambia(FILE *ap1, FILE *ap2)
{
    int i, j, k;
    char cad[30], cad1[100], aux[100];
    char *cad2;
    
    while (fgets(cad, 30, ap1) != NULL)
    {
        strcpy(cad1, cad);
        cad2 = strstr(cad1, "mexico");
        
        while (cad2 != NULL)
        {
            cad2[0] = 'M';
            i = (int)strlen(cad1);
            j = (int)strlen(cad2);
            k = i - j;
            
            if (k > 0)
            {
                strncpy(aux, cad1, k);
                aux[k] = '\0';
                strcat(aux, cad2);
                strcpy(cad1, aux);
            }
            else
            {
                strcpy(cad1, cad2);
            }
            cad2 = strstr(cad1 + 1, "mexico");
        }
        fputs(cad1, ap2);
    }
}