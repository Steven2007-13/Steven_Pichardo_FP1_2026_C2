#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char noba[10];        
    char nucu[10];        
} banco;

typedef union 
{
    banco che;            
    banco nomi;           
    char venta;           
} fpago;

typedef struct 
{
    char cnu[20];         
    char col[20];         
    char cp[5];           
    char ciu[15];         
} domicilio;

typedef struct 
{
    int num;             
    char nom[20];        
    float ven[12];        
    domicilio domi;      
    float sal;             
    fpago pago;            
    int cla;               
} vendedor;

void Lectura(vendedor A[], int T);
void F1(vendedor A[], int T);
void F2(vendedor A[], int T); 
void F3(vendedor A[], int T);
void F4(vendedor A[], int T);

void main(void)
{
    vendedor VENDEDORES[100]; 
    int TAM;
    
    do
    {
        printf("Ingrese el numero de vendedores (1-100): ");
        scanf("%d", &TAM);
    }    
    while(TAM > 100 || TAM < 1);
    
    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM); 
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);
    
    printf("\n\tFIN DEL PROGRAMA\n");
}

void Lectura(vendedor A[], int T)
{
    int I, J;
    for (I = 0; I < T; I++)
    {
        printf("\n\tIngrese datos del vendedor %d", I + 1);
        printf("\nNumero de vendedor: ");
        scanf("%d", &A[I].num);
        
        printf("Nombre del vendedor: ");
        while (getchar() != '\n');
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        for (int j = 0; A[I].nom[j] != '\0'; j++) {
            if (A[I].nom[j] == '\n') { A[I].nom[j] = '\0'; break; }
        }

        printf("Ventas del ano: \n");
        for (J = 0; J < 12; J++)
        {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }
        
        printf("Domicilio del vendedor: \n");
        printf("\tCalle y numero: ");
        while (getchar() != '\n');
        fgets(A[I].domi.cnu, sizeof(A[I].domi.cnu), stdin);
        for (int j = 0; A[I].domi.cnu[j] != '\0'; j++) {
            if (A[I].domi.cnu[j] == '\n') { A[I].domi.cnu[j] = '\0'; break; }
        }

        printf("\tColonia: ");
        fgets(A[I].domi.col, sizeof(A[I].domi.col), stdin);
        for (int j = 0; A[I].domi.col[j] != '\0'; j++) {
            if (A[I].domi.col[j] == '\n') { A[I].domi.col[j] = '\0'; break; }
        }

        printf("\tCodigo Postal: ");
        fgets(A[I].domi.cp, sizeof(A[I].domi.cp), stdin);
        for (int j = 0; A[I].domi.cp[j] != '\0'; j++) {
            if (A[I].domi.cp[j] == '\n') { A[I].domi.cp[j] = '\0'; break; }
        }

        printf("\tCiudad: ");
        fgets(A[I].domi.ciu, sizeof(A[I].domi.ciu), stdin);
        for (int j = 0; A[I].domi.ciu[j] != '\0'; j++) {
            if (A[I].domi.ciu[j] == '\n') { A[I].domi.ciu[j] = '\0'; break; }
        }

        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);
        
        printf("Forma de Pago (Banco-1 Nomina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);
        
        switch(A[I].cla)
        {
            case 1:
                while (getchar() != '\n');
                printf("\tNombre del banco: ");
                fgets(A[I].pago.che.noba, sizeof(A[I].pago.che.noba), stdin);
                for (int j = 0; A[I].pago.che.noba[j] != '\0'; j++) {
                    if (A[I].pago.che.noba[j] == '\n') { A[I].pago.che.noba[j] = '\0'; break; }
                }
                
                printf("\tNumero de cuenta: ");
                fgets(A[I].pago.che.nucu, sizeof(A[I].pago.che.nucu), stdin);
                for (int j = 0; A[I].pago.che.nucu[j] != '\0'; j++) {
                    if (A[I].pago.che.nucu[j] == '\n') { A[I].pago.che.nucu[j] = '\0'; break; }
                }
                break;
                
            case 2:
                while (getchar() != '\n');
                printf("\tNombre del banco: ");
                fgets(A[I].pago.nomi.noba, sizeof(A[I].pago.nomi.noba), stdin);
                for (int j = 0; A[I].pago.nomi.noba[j] != '\0'; j++) {
                    if (A[I].pago.nomi.noba[j] == '\n') { A[I].pago.nomi.noba[j] = '\0'; break; }
                }
                
                printf("\tNumero de cuenta: ");
                fgets(A[I].pago.nomi.nucu, sizeof(A[I].pago.nomi.nucu), stdin);
                for (int j = 0; A[I].pago.nomi.nucu[j] != '\0'; j++) {
                    if (A[I].pago.nomi.nucu[j] == '\n') { A[I].pago.nomi.nucu[j] = '\0'; break; }
                }
                break;
                
            case 3: 
                A[I].pago.venta = 'S';
                break;
        }
    }
}

void F1(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\n\t\tVentas Totales de los Vendedores\n");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
        {
            SUM += A[I].ven[J];
        }
        printf("\nNumero de vendedor: %d\tVentas Totales: %.2f\n", A[I].num, SUM);
    }
}

void F2(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\n\t\tVendedores con Ventas > 1,500,000\n");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
        {
            SUM += A[I].ven[J];
        }
        if (SUM > 1500000.00)
        {
            A[I].sal = A[I].sal * 1.05;
            printf("\nNumero de empleado: %d\nVentas: %.2f\nNuevo salario: %.2f\n", A[I].num, SUM, A[I].sal);
        } 
    }
}

void F3(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\n\t\tVendedores con Ventas < 300,000\n");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for(J = 0; J < 12; J++)
        {
            SUM += A[I].ven[J];
        }
        if(SUM < 300000.00)
        {
            printf("\nNumero de empleado: %d\nNombre: %s\nVentas: %.2f\n", A[I].num, A[I].nom, SUM);
        }
    }
}

void F4(vendedor A[], int T)
{
    int I;
    printf("\n\t\tVendedores con Cuenta en el Banco\n");
    for (I = 0; I < T; I++)
    {
        if(A[I].cla == 1)
        {
            printf("\nNumero de vendedor: %d\n Banco: %sCuenta: %s\n", A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
        }
    }
}