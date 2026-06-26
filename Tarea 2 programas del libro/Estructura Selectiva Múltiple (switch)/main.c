#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    float precio_original = 0.0;
    float precio_final = 0.0;

    printf("--- Sistema de Caja - Tienda de Ropa ---\n\n");
    printf("Ingrese el precio de la prenda: $");
    scanf("%f", &precio_original);
    while(getchar() !='\n');

    printf("\n--- Tipos de clientes ---\n\n");
    printf("1. Cliente premium (30%% de descuento)\n");
    printf("2. Estudiante (15%% de descuento)\n");
    printf("3. Cliente regular (sin descuento)\n");
    printf("\nSelecciona el tipo de cliente (1-3): ");
    scanf("%i", &opcion);
    while(getchar() !='\n');

    switch(opcion)
    {
    case 1:
        precio_final = precio_original * 0.70;
        printf("\n\nDescuento premium aplicado!\n");
        printf("El total a pagar es: $%.2f\n", precio_final);
        break;
    case 2:
        precio_final = precio_original * 0.85;
        printf("\n\nDescuento edtudiantil aplicado!\n");
        printf("El total a pagar es: $%.2f\n", precio_final);
        break;
    case 3:
        precio_final = precio_original;
        printf("\n\nCliente regular sin descuentos.\n");
        printf("El total a pagar es: $%.2f\n", precio_final);
        break;
    default:
        printf("\n\nOpcion no valida. Se cobrara el precio completo: $%.2f",precio_original);
    }
    return 0;
}
