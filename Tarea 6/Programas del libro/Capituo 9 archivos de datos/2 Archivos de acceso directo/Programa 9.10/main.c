#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void modifica(FILE *ap);

void main(void)
{
    FILE *ar;
    ar = fopen("c:\\temp\\ad1.dat", "r+");
    
    if (ar != NULL)
    {
        modifica(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir\n");
    }
}

void modifica(FILE *ap)
{
    int d;
    alumno alu;
    
    printf("\nIngrese el numero de registro que desea modificar: ");
    scanf("%d", &d);
    
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);
    
    fread(&alu, sizeof(alumno), 1, ap);
    
    printf("\nIngrese el promedio correcto del alumno: ");
    scanf("%f", &alu.promedio);   
    
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);
    
    fwrite(&alu, sizeof(alumno), 1, ap);
}