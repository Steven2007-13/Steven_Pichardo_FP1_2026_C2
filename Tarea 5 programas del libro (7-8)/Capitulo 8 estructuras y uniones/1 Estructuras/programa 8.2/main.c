#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};

void Lectura(struct alumno *);

void main(void)
{
    struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"};
    struct alumno *a3, *a4, *a5, a6;

    a3 = &a0; 
    
    a4 = (struct alumno *)malloc(sizeof(struct alumno));

    printf("\nIngrese la matricula del alumno 4: ");
    scanf("%d", &(*a4).matricula);
    
    while (getchar() != '\n');
    
    printf("Ingrese el nombre del alumno 4: ");
    fgets(a4->nombre, sizeof(a4->nombre), stdin);
    for (int j = 0; a4->nombre[j] != '\0'; j++) {
        if (a4->nombre[j] == '\n') { a4->nombre[j] = '\0'; break; }
    }

    printf("Ingrese la carrera del alumno 4: ");
    fgets((*a4).carrera, sizeof((*a4).carrera), stdin);
    for (int j = 0; a4->carrera[j] != '\0'; j++) {
        if (a4->carrera[j] == '\n') { a4->carrera[j] = '\0'; break; }
    }

    printf("Ingrese promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    
    while (getchar() != '\n');
    
    printf("Ingrese la direccion del alumno 4: ");
    fgets(a4->direccion, sizeof(a4->direccion), stdin);
    for (int j = 0; a4->direccion[j] != '\0'; j++) {
        if (a4->direccion[j] == '\n') { a4->direccion[j] = '\0'; break; }
    }

    a5 = (struct alumno *)malloc(sizeof(struct alumno));
    Lectura(a5);     
    Lectura(&a6);  

    printf("\nDatos del alumno 3\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a3->matricula, a3->nombre, a3->carrera, a3->promedio, a3->direccion);
    
    printf("\nDatos del alumno 4\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a4->matricula, a4->nombre, a4->carrera, a4->promedio, a4->direccion);
    
    printf("\nDatos del alumno 5\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a5->matricula, a5->nombre, a5->carrera, a5->promedio, a5->direccion);
    
    printf("\nDatos del alumno 6\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a6.matricula, a6.nombre, a6.carrera, a6.promedio, a6.direccion);

    free(a4);
    free(a5);
}

void Lectura(struct alumno *a)
{
    printf("\nIngrese la matricula del alumno: ");
    scanf("%d", &(*a).matricula);
    
    while (getchar() != '\n');
    
    printf("Ingrese el nombre del alumno: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    for (int j = 0; a->nombre[j] != '\0'; j++) {
        if (a->nombre[j] == '\n') { a->nombre[j] = '\0'; break; }
    }
    
    while (getchar() != '\n');
    
    printf("Ingrese la carrera del alumno: ");
    fgets((*a).carrera, sizeof((*a).carrera), stdin);
    for (int j = 0; a->carrera[j] != '\0'; j++) {
        if (a->carrera[j] == '\n') { a->carrera[j] = '\0'; break; }
    }
    
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    
    while (getchar() != '\n');
    
    printf("Ingrese la direccion del alumno: ");
    fgets(a->direccion, sizeof(a->direccion), stdin);
    for (int j = 0; a->direccion[j] != '\0'; j++) {
        if (a->direccion[j] == '\n') { a->direccion[j] = '\0'; break; }
    }
}