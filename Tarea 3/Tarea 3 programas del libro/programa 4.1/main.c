#include <stdio.h>
#include <stdlib.h>

/* Funciones básicas.
El programa utiliza funciones simples para imprimir un encabezado y unas líneas. */

/* Prototipos de funciones */
void encabezado(void);
void linea(void);

int main()
{
    printf("--- PROGRAMA 4.1: PRUEBA DE FUNCIONES ---\n\n");

    encabezado(); /* Llamada a la función encabezado */
    printf("\n*Cuerpo del texto\n\n");
    linea();      /* Llamada a la función linea */
    printf("\n*Conclusion\n\n");
    linea();      /* Podemos reutilizar las funciones las veces que queramos */
    printf("\nEl programa ha ejecutado las funciones correctamente.\n\n");
    return 0;
}

/* Definición de la función encabezado */
void encabezado(void)
{
    printf("=========================================\n");
    printf("  INSTITUTO TECNOLOGICO DE LAS AMERICAS  \n");
    printf("=========================================\n");
}

/* Definición de la función linea */
void linea(void)
{
    printf("-----------------------------------------\n");
}
