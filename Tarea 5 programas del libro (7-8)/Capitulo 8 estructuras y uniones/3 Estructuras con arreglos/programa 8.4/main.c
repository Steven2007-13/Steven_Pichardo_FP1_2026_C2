#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int matricula;
    char nombre[30];
    float cal[5];
} alumno;

void Lectura(alumno A[], int T);
void F1(alumno A[], int T);
void F2(alumno A[], int T);
void F3(alumno A[], int T);

void main(void)
{
    alumno ARRE[50];
    int TAM;
    
    do
    {
        printf("Ingrese el tamano del arreglo (1-50): ");
        scanf("%d", &TAM);
    }
    while(TAM > 50 || TAM < 1);

    Lectura(ARRE, TAM);
    F1(ARRE, TAM);
    F2(ARRE, TAM);
    F3(ARRE, TAM);
    printf("\n");
}

void Lectura(alumno A[], int T)
{
    int I, J;
    for (I = 0; I < T; I++)
    {
        printf("\nIngrese los datos del alumno %d", I + 1);
        printf("\nIngrese la matricula del alumno: ");
        scanf("%d", &A[I].matricula);
        
        while (getchar() != '\n');
        
        printf("Ingrese el nombre del alumno: ");
        fgets(A[I].nombre, sizeof(A[I].nombre), stdin);
        for (J = 0; A[I].nombre[J] != '\0'; J++)
        {
            if (A[I].nombre[J] == '\n')
            {
                A[I].nombre[J] = '\0';
                break;
            }
        }

        for (J = 0; J < 5; J++)
        {
            printf("\tIngrese la calificacion %d del alumno %d: ", J + 1, I + 1);
            scanf("%f", &A[I].cal[J]);
        }
    }
}

void F1(alumno A[], int T)
{
    int I, J;
    float SUM, PRO;
    
    printf("\n--- Promedios individuales ---");
    for (I = 0; I < T; I++)
    {
        printf("\nMatricula del alumno: %d", A[I].matricula);
        SUM = 0.0;
        for (J = 0; J < 5; J++)
        {
            SUM = SUM + A[I].cal[J];
        }
        PRO = SUM / 5.0;
        printf("\t\tPromedio: %.2f", PRO);
    }
}

void F2(alumno A[], int T)
{
    int I;
    printf("\n\nAlumnos con calificacion en la tercera materia > 9");
    for (I = 0; I < T; I++)
    {
        if (A[I].cal[2] > 9.0)
        {
            printf("\nMatricula del alumno: %d", A[I].matricula);
        }
    }
}

void F3(alumno A[], int T)
{
    int I;
    float PRO, SUM = 0.0;
    for (I = 0; I < T; I++)
    {
        SUM = SUM + A[I].cal[3];
    }
    PRO = SUM / T;
    printf("\n\nPromedio de la materia 4: %.2f\n", PRO);
}