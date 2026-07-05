#include <stdio.h>
#include <stdlib.h>

void promedio(FILE *ar1);

void main(void)
{
    FILE *ar;
    ar = fopen("c:\\temp\\arc8.txt", "r");
    if (ar != NULL)
    {
        promedio(ar);       
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }
}

void promedio(FILE *ar1) 
{
    int i, j, n, mat;
    float pro, cal;
    
    if (fscanf(ar1, "%d", &n) != 1) return;
    
    for (i = 0; i < n; i++)
    {
        if (fscanf(ar1, "%d", &mat) != 1) break;
        printf("%d\t", mat);
        pro = 0;
        for (j = 0; j < 5; j++)
        {
            if (fscanf(ar1, "%f", &cal) != 1) break;
            pro += cal;
        }
        printf("\t %.2f  ", pro / 5.0);
        printf("\n");
    }
}