#include <stdio.h>
#include <stdlib.h>

typedef struct                          
{
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void incrementa(FILE *ap);

void main(void)
{
    FILE *ar;
    ar = fopen("c:\\temp\\ad5.dat", "r+");
    
    if (ar != NULL) 
    {
        incrementa(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir\n");
    }
}

void incrementa(FILE *ap)
{
    int i, j, t;
    float sum;
    empleado emple;
    
    t = sizeof(empleado);
    
    fread(&emple, sizeof(empleado), 1, ap);   
    
    while(!feof(ap))
    {
        i = ftell(ap) / t;
        
        sum = 0;
        for (j = 0; j < 12; j++)
        {
            sum += emple.ventas[j];  
        }
            
        if (sum > 1000000.0f)
        {
            emple.salario = emple.salario * 1.10f;  
            
            fseek(ap, (i - 1) * sizeof(empleado), SEEK_SET);  
            fwrite(&emple, sizeof(empleado), 1, ap);
            
            fseek(ap, i * sizeof(empleado), SEEK_SET);
        }
        
        fread(&emple, sizeof(empleado), 1, ap);
    }
}