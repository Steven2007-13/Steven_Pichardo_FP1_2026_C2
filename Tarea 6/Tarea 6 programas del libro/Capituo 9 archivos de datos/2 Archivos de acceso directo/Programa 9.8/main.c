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

void escribe(FILE *ap);         

void main(void)
{ 
    FILE *ar;
    ar = fopen("c:\\temp\\ad1.dat", "w");
    
    if (ar != NULL)
    {
        escribe(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir\n");
    }
}

void escribe(FILE *ap)
{
    alumno alu;
    int i = 0, r;
    
    printf("\nDesea ingresar informacion sobre alumnos? (Si-1 No-0): ");
    scanf("%d", &r);
    
    while (r)
    {
        i++;
        printf("Matricula del alumno %d: ", i);
        scanf("%d", &alu.matricula);
        
        printf("Nombre del alumno %d: ", i);
        while (getchar() != '\n');
        fgets(alu.nombre, sizeof(alu.nombre), stdin);
        for (int j = 0; alu.nombre[j] != '\0'; j++) {
            if (alu.nombre[j] == '\n') { alu.nombre[j] = '\0'; break; }
        }
        
        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);
        
        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);
        
        fwrite(&alu, sizeof(alumno), 1, ap);
        
        printf("\nDesea ingresar informacion sobre mas alumnos? (Si-1 No-0): ");
        scanf("%d", &r);
    }
}