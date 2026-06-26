#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char cal[20];         
    int num;              
    char col[20];         
    char cp[5];           
    char ciu[20];         
} domicilio;

typedef struct 
{
    char nom[20];         
    int edad;
    char sexo;
    int con;              
    domicilio dom;          
    char tel[10];         
} paciente;

void Lectura(paciente A[], int T);   
void F1(paciente A[], int T);
void F2(paciente A[], int T);                
void F3(paciente A[], int T);

void main(void)
{
    paciente HOSPITAL[100];   
    int TAM;
    
    do
    {
        printf("Ingrese el numero de pacientes (1-50): ");
        scanf("%d", &TAM);
    }
    while(TAM > 50 || TAM < 1);   
    
    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);
    printf("\n");
}

void Lectura(paciente A[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("\n\t\tPaciente %d", I + 1);
        
        while (getchar() != '\n');
        
        printf("\nNombre: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        for (int j = 0; A[I].nom[j] != '\0'; j++) {
            if (A[I].nom[j] == '\n') { A[I].nom[j] = '\0'; break; }
        }

        printf("Edad: ");
        scanf("%d", &A[I].edad);
        
        while (getchar() != '\n');
        
        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);
        
        printf("Condicion (1..5): ");
        scanf("%d", &A[I].con);
        
        while (getchar() != '\n');
        
        printf("\tCalle: ");
        fgets(A[I].dom.cal, sizeof(A[I].dom.cal), stdin);
        for (int j = 0; A[I].dom.cal[j] != '\0'; j++) {
            if (A[I].dom.cal[j] == '\n') { A[I].dom.cal[j] = '\0'; break; }
        }

        printf("\tNumero: ");
        scanf("%d", &A[I].dom.num);
        
        while (getchar() != '\n');
        
        printf("\tColonia: ");
        fgets(A[I].dom.col, sizeof(A[I].dom.col), stdin);
        for (int j = 0; A[I].dom.col[j] != '\0'; j++) {
            if (A[I].dom.col[j] == '\n') { A[I].dom.col[j] = '\0'; break; }
        }

        printf("\tCodigo Postal: ");
        fgets(A[I].dom.cp, sizeof(A[I].dom.cp), stdin);
        for (int j = 0; A[I].dom.cp[j] != '\0'; j++) {
            if (A[I].dom.cp[j] == '\n') { A[I].dom.cp[j] = '\0'; break; }
        }

        printf("\tCiudad: ");
        fgets(A[I].dom.ciu, sizeof(A[I].dom.ciu), stdin);
        for (int j = 0; A[I].dom.ciu[j] != '\0'; j++) {
            if (A[I].dom.ciu[j] == '\n') { A[I].dom.ciu[j] = '\0'; break; }
        }

        printf("Telefono: ");
        fgets(A[I].tel, sizeof(A[I].tel), stdin);
        for (int j = 0; A[I].tel[j] != '\0'; j++) {
            if (A[I].tel[j] == '\n') { A[I].tel[j] = '\0'; break; }
        }
    }
}

void F1(paciente A[], int T)
{
    int I, FEM = 0, MAS = 0, TOT;
    for (I = 0; I < T; I++)
    {
        if (A[I].sexo == 'F' || A[I].sexo == 'f')
        {
            FEM++;
        }
        else if (A[I].sexo == 'M' || A[I].sexo == 'm')
        {
            MAS++;
        }
    }
    
    TOT = FEM + MAS;
    
    if (TOT == 0)
    {
        printf("\nNo hay pacientes registrados para calcular porcentajes.");
    }
    else
    {
        printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
        printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
    }
}

void F2(paciente A[], int T)
{
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
    for (I = 0; I < T; I++)
    {
        switch(A[I].con)
        {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }
    
    printf("\n\nNumero pacientes en condicion 1: %d", C1);
    printf("\nNumero pacientes en condicion 2: %d", C2);
    printf("\nNumero pacientes en condicion 3: %d", C3);
    printf("\nNumero pacientes en condicion 4: %d", C4);
    printf("\nNumero pacientes en condicion 5: %d", C5);
}

void F3(paciente A[], int T)
{
    int I;
    printf("\n\nPacientes ingresados en estado de gravedad");
    for (I = 0; I < T; I++)
    {
        if (A[I].con == 5)
        {
            printf("\nNombre: %s\tTelefono: %s", A[I].nom, A[I].tel);
        }
    }
}