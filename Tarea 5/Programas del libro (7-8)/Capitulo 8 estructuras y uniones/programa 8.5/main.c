#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union datos 
{
    char celular[15];
    char correo[20];
};

typedef struct 
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;      
} alumno;

void Lectura(alumno *a);

void main(void)
{
    // Nota: e.g. a1 tiene inicializado el campo celular ("5-158-40-50").
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, {"5-158-40-50"}}, a2, a3, a0;

    printf("Alumno 2\n");
    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    
    while (getchar() != '\n');
    
    printf("Ingrese el nombre: ");
    fgets(a2.nombre, sizeof(a2.nombre), stdin);
    for (int j = 0; a2.nombre[j] != '\0'; j++) {
        if (a2.nombre[j] == '\n') { a2.nombre[j] = '\0'; break; }
    }

    printf("Ingrese la carrera: ");
    fgets(a2.carrera, sizeof(a2.carrera), stdin);
    for (int j = 0; a2.carrera[j] != '\0'; j++) {
        if (a2.carrera[j] == '\n') { a2.carrera[j] = '\0'; break; }
    }

    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    
    while (getchar() != '\n');
     
    printf("Ingrese el correo electronico: ");
    fgets(a2.personales.correo, sizeof(a2.personales.correo), stdin);
    for (int j = 0; a2.personales.correo[j] != '\0'; j++) {
        if (a2.personales.correo[j] == '\n') { a2.personales.correo[j] = '\0'; break; }
    }

    printf("Alumno 3\n");
    Lectura(&a3);  

    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular); 
    puts(a1.personales.correo);

    strcpy(a0.personales.correo, "hgimenez@hotmail.com");
    puts(a0.personales.celular);
    puts(a0.personales.correo);

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular);        
    puts(a2.personales.correo);          
    
    printf("Ingrese el telefono celular del alumno 2: ");
    fgets(a2.personales.celular, sizeof(a2.personales.celular), stdin);
    for (int j = 0; a2.personales.celular[j] != '\0'; j++) {
        if (a2.personales.celular[j] == '\n') { a2.personales.celular[j] = '\0'; break; }
    }
    
    puts(a2.personales.celular);        
    puts(a2.personales.correo);         

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);
    puts(a3.personales.correo);         
} 

void Lectura(alumno *a)
{
    printf("\nIngrese la matricula: ");
    scanf("%d", &(*a).matricula);
    
    while (getchar() != '\n');
    
    printf("Ingrese el nombre: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    for (int j = 0; a->nombre[j] != '\0'; j++) {
        if (a->nombre[j] == '\n') { a->nombre[j] = '\0'; break; }
    }
    
    printf("Ingrese la carrera: ");
    fgets(a->carrera, sizeof(a->carrera), stdin);
    for (int j = 0; a->carrera[j] != '\0'; j++) {
        if (a->carrera[j] == '\n') { a->carrera[j] = '\0'; break; }
    }
    
    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    
    while (getchar() != '\n');
    
    printf("Ingrese el telefono celular: ");
    fgets(a->personales.celular, sizeof(a->personales.celular), stdin);
    for (int j = 0; a->personales.celular[j] != '\0'; j++) {
        if (a->personales.celular[j] == '\n') { a->personales.celular[j] = '\0'; break; }
    }
}