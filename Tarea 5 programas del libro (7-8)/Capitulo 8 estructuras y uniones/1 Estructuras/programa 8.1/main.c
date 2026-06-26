#include <stdio.h>
#include <string.h>

struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[20]; 
    float promedio;
    char direccion[20];
};

void main(void)
{
    struct alumno a1 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"}, a2, a3;
    
    char nom[20], car[20], dir[20];
    int mat;
    float pro;

    printf("\nIngrese la matricula del alumno 2: ");
    scanf("%d", &a2.matricula);

    while (getchar() != '\n');
    
    printf("Ingrese el nombre del alumno 2: ");
    fgets(a2.nombre, sizeof(a2.nombre), stdin);
    for (int j = 0; a2.nombre[j] != '\0'; j++) {
        if (a2.nombre[j] == '\n') { a2.nombre[j] = '\0'; break; }
    }

    printf("Ingrese la carrera del alumno 2: ");
    fgets(a2.carrera, sizeof(a2.carrera), stdin);
    for (int j = 0; a2.carrera[j] != '\0'; j++) {
        if (a2.carrera[j] == '\n') { a2.carrera[j] = '\0'; break; }
    }

    printf("Ingrese el promedio del alumno 2: ");
    scanf("%f", &a2.promedio);

    while (getchar() != '\n');

    printf("Ingrese la direccion del alumno 2: ");
    fgets(a2.direccion, sizeof(a2.direccion), stdin);
    for (int j = 0; a2.direccion[j] != '\0'; j++) {
        if (a2.direccion[j] == '\n') { a2.direccion[j] = '\0'; break; }
    }

    printf("\nIngrese la matricula del alumno 3: ");
    scanf("%d", &mat);
    a3.matricula = mat;

    while (getchar() != '\n');

    printf("Ingrese el nombre del alumno 3: ");
    fgets(nom, sizeof(nom), stdin); 
    for (int j = 0; nom[j] != '\0'; j++) {
        if (nom[j] == '\n') { nom[j] = '\0'; break; }
    }
    strcpy(a3.nombre, nom);

    printf("Ingrese la carrera del alumno 3: ");
    fgets(car, sizeof(car), stdin);
    for (int j = 0; car[j] != '\0'; j++) {
        if (car[j] == '\n') { car[j] = '\0'; break; }
    }
    strcpy(a3.carrera, car);

    printf("Ingrese el promedio del alumno 3: ");
    scanf("%f", &pro);
    a3.promedio = pro;

    while (getchar() != '\n');

    printf("Ingrese la direccion del alumno 3: ");
    fgets(dir, sizeof(dir), stdin);
    for (int j = 0; dir[j] != '\0'; j++) {
        if (dir[j] == '\n') { dir[j] = '\0'; break; }
    }
    strcpy(a3.direccion, dir);

    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.direccion);

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.direccion);

    printf("\nDatos del alumno 3\n");
    printf("%d \t %s \t %s \t %.2f \t %s\n", a3.matricula, a3.nombre, a3.carrera, a3.promedio, a3.direccion);
}