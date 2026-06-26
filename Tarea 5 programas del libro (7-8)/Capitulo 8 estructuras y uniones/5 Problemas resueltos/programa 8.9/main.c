#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char zona[20];
    char calle[20];
    char colo[20];
} ubicacion;

typedef struct 
{
    char clave[5];
    float scu;              
    float ste;              
    char car[50];           
    ubicacion ubi;             
    float precio;
    char dispo;                
} propiedades;

void Lectura(propiedades A[], int T);
void F1(propiedades A[], int T);
void F2(propiedades A[], int T); 

void main(void)
{
    propiedades PROPIE[100];      
    int TAM;
    
    do
    {
        printf("Ingrese el numero de propiedades (1-100): ");
        scanf("%d", &TAM);
    }
    while(TAM > 100 || TAM < 1);  
    
    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);
    printf("\n");
}

void Lectura(propiedades A[], int T)
{
    int I;
    for (I = 0; I < T; I++) 
    {
        printf("\n\tIngrese datos de la propiedad %d", I + 1);
        printf("\nClave: ");
        
        while (getchar() != '\n');
        
        fgets(A[I].clave, sizeof(A[I].clave), stdin);
        for (int j = 0; A[I].clave[j] != '\0'; j++) {
            if (A[I].clave[j] == '\n') { A[I].clave[j] = '\0'; break; }
        }

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);
        
        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);
        
        printf("Caracteristicas: ");
        while (getchar() != '\n');
        fgets(A[I].car, sizeof(A[I].car), stdin);
        for (int j = 0; A[I].car[j] != '\0'; j++) {
            if (A[I].car[j] == '\n') { A[I].car[j] = '\0'; break; }
        }

        printf("\tZona: ");
        fgets(A[I].ubi.zona, sizeof(A[I].ubi.zona), stdin);
        for (int j = 0; A[I].ubi.zona[j] != '\0'; j++) {
            if (A[I].ubi.zona[j] == '\n') { A[I].ubi.zona[j] = '\0'; break; }
        }

        printf("\tCalle: ");
        fgets(A[I].ubi.calle, sizeof(A[I].ubi.calle), stdin);
        for (int j = 0; A[I].ubi.calle[j] != '\0'; j++) {
            if (A[I].ubi.calle[j] == '\n') { A[I].ubi.calle[j] = '\0'; break; }
        }

        printf("\tColonia: ");
        fgets(A[I].ubi.colo, sizeof(A[I].ubi.colo), stdin);
        for (int j = 0; A[I].ubi.colo[j] != '\0'; j++) {
            if (A[I].ubi.colo[j] == '\n') { A[I].ubi.colo[j] = '\0'; break; }
        }

        printf("Precio: ");
        scanf("%f", &A[I].precio);
        
        while (getchar() != '\n');
        
        printf("Disponibilidad (Venta-V, Renta-R): ");
        scanf("%c", &A[I].dispo);
    }
}

void F1(propiedades A[], int T)
{
    int I;
    printf("\n\t\tListado de Propiedades para Venta en Miraflores\n");
    for (I = 0; I < T; I++)
    {
        if ((A[I].dispo == 'V' || A[I].dispo == 'v') && 
            (strcmp(A[I].ubi.zona, "Miraflores") == 0 || strcmp(A[I].ubi.zona, "miraflores") == 0) && 
            (A[I].precio >= 450000) && (A[I].precio <= 650000))
        {
            printf("\nClave de la propiedad: %s", A[I].clave);
            printf("\nSuperficie cubierta: %.2f", A[I].scu);
            printf("\nSuperficie terreno: %.2f", A[I].ste);
            printf("\nCaracteristicas: %s", A[I].car);
            printf("Calle: %s", A[I].ubi.calle);
            printf("Colonia: %s", A[I].ubi.colo);
            printf("Precio: %.2f\n", A[I].precio);
        }
    }
}

void F2(propiedades A[], int T)
{
    int I;
    float li, ls;
    char zon[20];
    
    printf("\n\t\tListado de Propiedades para Renta");
    printf("\nIngrese zona geografica: "); 
    
    while (getchar() != '\n');
    
    fgets(zon, sizeof(zon), stdin);
    for (int j = 0; zon[j] != '\0'; j++) {
        if (zon[j] == '\n') { zon[j] = '\0'; break; }
    }
    
    printf("Ingrese el limite inferior del precio: ");
    scanf("%f", &li);
    
    printf("Ingrese el limite superior del precio: ");
    scanf("%f", &ls);
    
    for (I = 0; I < T; I++)
    {
        if ((A[I].dispo == 'R' || A[I].dispo == 'r') && 
            (strcmp(A[I].ubi.zona, zon) == 0) && 
            (A[I].precio >= li) && (A[I].precio <= ls))
        {
            printf("\nClave de la propiedad: %s", A[I].clave);
            printf("\nSuperficie cubierta: %.2f", A[I].scu);
            printf("\nSuperficie terreno: %.2f", A[I].ste); 
            printf("\nCaracteristicas: %s", A[I].car);
            printf("Calle: %s", A[I].ubi.calle);
            printf("Colonia: %s", A[I].ubi.colo);
            printf("Precio: %.2f\n", A[I].precio);
        }
    }
}