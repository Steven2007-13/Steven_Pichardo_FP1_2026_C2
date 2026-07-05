#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int i, j, n, mat;
    float cal;
    FILE *ar;
    
    printf("\nIngrese el numero de alumnos: ");
    scanf("%d", &n);   
    
    ar = fopen("c:\\temp\\arc8.txt", "w");
    if (ar != NULL)
    {
        fprintf(ar, "%d\n", n);          
        
        for (i = 0; i < n; i++)
        {
            printf("\nIngrese la matricula del alumno %d: ", i + 1);
            scanf("%d", &mat);
            
            fprintf(ar, "%d", mat);   
            
            for (j = 0; j < 5; j++)
            {
                printf("\nCalificacion %d: ", j + 1);
                scanf("%f", &cal);
                
                fprintf(ar, " %.2f", cal);   
            }
            
            if (i < n - 1) 
            {
                fprintf(ar, "\n");
            }
        }
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }
}