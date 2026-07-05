#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {           
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void lee(FILE *ap);    

void main(void)
{
    FILE *ar;
    ar = fopen("c:\\temp\\ad1.dat", "r");
    
    if (ar != NULL)
    {
        lee(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir\n");
    }
}

void lee(FILE *ap)
{
    alumno alu;
    
    fread(&alu, sizeof(alumno), 1, ap);
    
    while (!feof(ap))
    {   
        printf("\n Matricula: %d", alu.matricula);
        printf("\t Carrera: %d", alu.carrera);
        printf("\t Promedio: %.2f\t ", alu.promedio);
        puts(alu.nombre);
        
        fread(&alu, sizeof(alumno), 1, ap);
    }
}