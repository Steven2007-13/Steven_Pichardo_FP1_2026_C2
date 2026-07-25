#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado 
{
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion; 
};

void Lectura(struct empleado *a)
{
    printf("\nIngrese el nombre del empleado: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    for (int j = 0; a->nombre[j] != '\0'; j++) {
        if (a->nombre[j] == '\n') { a->nombre[j] = '\0'; break; }
    }

    printf("Ingrese el departamento de la empresa: ");
    fgets(a->departamento, sizeof(a->departamento), stdin);
    for (int j = 0; a->departamento[j] != '\0'; j++) {
        if (a->departamento[j] == '\n') { a->departamento[j] = '\0'; break; }
    }

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    
    while (getchar() != '\n');
    
    printf("----Ingrese la direccion del empleado----");
    printf("\n\tCalle: ");
    fgets(a->direccion.calle, sizeof(a->direccion.calle), stdin);
    for (int j = 0; a->direccion.calle[j] != '\0'; j++) {
        if (a->direccion.calle[j] == '\n') { a->direccion.calle[j] = '\0'; break; }
    }

    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    
    printf("\tCodigo Postal: ");
    scanf("%d", &a->direccion.cp);
    
    while (getchar() != '\n');
    
    printf("\tLocalidad: ");
    fgets(a->direccion.localidad, sizeof(a->direccion.localidad), stdin);
    for (int j = 0; a->direccion.localidad[j] != '\0'; j++) {
        if (a->direccion.localidad[j] == '\n') { a->direccion.localidad[j] = '\0'; break; }
    }
}

void main(void)
{
    struct empleado e0 = {"Arturo", "Compras", 15500.75, {"San Jeronimo", 120, 3490, "Toluca"}};
    struct empleado *e1, *e2, e3, e4;

    e1 = (struct empleado *)malloc(sizeof(struct empleado));
    
    printf("\nIngrese el nombre del empleado 1: ");
    fgets(e1->nombre, sizeof(e1->nombre), stdin);
    for (int j = 0; e1->nombre[j] != '\0'; j++) {
        if (e1->nombre[j] == '\n') { e1->nombre[j] = '\0'; break; }
    }

    printf("Ingrese el departamento de la empresa: ");
    fgets(e1->departamento, sizeof(e1->departamento), stdin);
    for (int j = 0; e1->departamento[j] != '\0'; j++) {
        if (e1->departamento[j] == '\n') { e1->departamento[j] = '\0'; break; }
    }

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    
    printf("----Ingrese la direccion del empleado----");
    
    while (getchar() != '\n');
    
    printf("\n\tCalle: ");
    fgets(e1->direccion.calle, sizeof(e1->direccion.calle), stdin);
    for (int j = 0; e1->direccion.calle[j] != '\0'; j++) {
        if (e1->direccion.calle[j] == '\n') { e1->direccion.calle[j] = '\0'; break; }
    }

    printf("\tNumero: ");
    scanf("%d", &e1->direccion.numero);
    
    printf("\tCodigo Postal: ");
    scanf("%d", &e1->direccion.cp);
    
    while (getchar() != '\n');
    
    printf("\tLocalidad: ");
    fgets(e1->direccion.localidad, sizeof(e1->direccion.localidad), stdin);
    for (int j = 0; e1->direccion.localidad[j] != '\0'; j++) {
        if (e1->direccion.localidad[j] == '\n') { e1->direccion.localidad[j] = '\0'; break; }
    }

    printf("\nIngrese el nombre del empleado 3: ");
    fgets(e3.nombre, sizeof(e3.nombre), stdin);
    for (int j = 0; e3.nombre[j] != '\0'; j++) {
        if (e3.nombre[j] == '\n') { e3.nombre[j] = '\0'; break; }
    }

    printf("Ingrese el departamento de la empresa: ");
    fgets(e3.departamento, sizeof(e3.departamento), stdin);
    for (int j = 0; e3.departamento[j] != '\0'; j++) {
        if (e3.departamento[j] == '\n') { e3.departamento[j] = '\0'; break; }
    }

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    
    printf("----Ingrese la direccion del empleado----");
    
    while (getchar() != '\n');
    
    printf("\n\tCalle: ");
    fgets(e3.direccion.calle, sizeof(e3.direccion.calle), stdin);
    for (int j = 0; e3.direccion.calle[j] != '\0'; j++) {
        if (e3.direccion.calle[j] == '\n') { e3.direccion.calle[j] = '\0'; break; }
    }

    printf("\tNumero: ");
    scanf("%d", &e3.direccion.numero);
    
    printf("\tCodigo Postal: ");
    scanf("%d", &e3.direccion.cp);
    
    while (getchar() != '\n');
    
    printf("\tLocalidad: ");
    fgets(e3.direccion.localidad, sizeof(e3.direccion.localidad), stdin);
    for (int j = 0; e3.direccion.localidad[j] != '\0'; j++) {
        if (e3.direccion.localidad[j] == '\n') { e3.direccion.localidad[j] = '\0'; break; }
    }

    e2 = (struct empleado *)malloc(sizeof(struct empleado));
    Lectura(e2);
    Lectura(&e4);

    printf("\nDatos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e1->nombre, e1->departamento, e1->sueldo, e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);

    printf("\nDatos del empleado 4\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e4.nombre, e4.departamento, e4.sueldo, e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);

    free(e1);
    free(e2);
}