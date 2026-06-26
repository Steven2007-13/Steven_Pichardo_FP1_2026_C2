#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char mat[20];   
    int pro;        
} matpro;

typedef struct                
{
    int matri;      
    char nom[20];   
    matpro cal[5];  
} alumno;

void Lectura(alumno *A, int T);
void F1(alumno *A, int T);
void F2(alumno *A, int T);                   
void F3(alumno *A, int T);

void main(void)
{
    alumno ALU[50];        
    int TAM;
    
    do
    {
        printf("Ingrese el tamano del arreglo (1-50): ");
        scanf("%d", &TAM);
    }
    while(TAM > 50 || TAM < 1);  
    
    Lectura(ALU, TAM);
    F1(ALU, TAM);
    F2(ALU, TAM);
    F3(ALU, TAM);
    printf("\n");
}

void Lectura(alumno A[], int T)
{
    int I, J;
    for(I = 0; I < T; I++)
    {
        printf("\nIngrese los datos del alumno %d", I + 1);
        printf("\nIngrese la matricula: ");
        scanf("%d", &A[I].matri);
        
        while (getchar() != '\n');
        
        printf("Ingrese el nombre del alumno: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        for (int j = 0; A[I].nom[j] != '\0'; j++) {
            if (A[I].nom[j] == '\n') { A[I].nom[j] = '\0'; break; }
        }

        for (J = 0; J < 5; J++)
        {
            while (getchar() != '\n');
            printf("\tIngrese el nombre de la materia %d: ", J + 1);
            fgets(A[I].cal[J].mat, sizeof(A[I].cal[J].mat), stdin);
            for (int j = 0; A[I].cal[J].mat[j] != '\0'; j++) {
                if (A[I].cal[J].mat[j] == '\n') { A[I].cal[J].mat[j] = '\0'; break; }
            }
            
            printf("\tIngrese el promedio de dicha materia: ");
            scanf("%d", &A[I].cal[J].pro);
        }
    }
}

void F1(alumno A[], int T)
{
    int I, J;
    float SUM;
    
    printf("\n--- Promedios generales de cada alumno ---");
    for(I = 0; I < T; I++)
    {
        printf("\nMatricula: %d", A[I].matri);
        SUM = 0.0;
        for(J = 0; J < 5; J++)
        {
            SUM = SUM + A[I].cal[J].pro;
        }
        SUM = SUM / 5.0;
        printf("\t\tPromedio: %.2f", SUM);
    }
}

void F2(alumno A[], int T)
{
    int I;
    printf("\n\nAlumnos con promedio en la tercera materia > 9");
    for (I = 0; I < T; I++)
    {
        if (A[I].cal[2].pro > 9)
        {
            printf("\nMatricula del alumno: %d", A[I].matri);
        }
    }
}

void F3(alumno A[], int T)
{
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++)
    {
        SUM = SUM + A[I].cal[3].pro;
    }
    SUM = SUM / T;
    printf("\n\nPromedio de la cuarta materia: %.2f\n", SUM);
}