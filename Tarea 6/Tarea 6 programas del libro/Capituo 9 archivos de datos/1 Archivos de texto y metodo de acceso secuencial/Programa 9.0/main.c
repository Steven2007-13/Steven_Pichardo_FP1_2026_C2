#include <stdio.h>

void main(void)
{
    FILE *apuntador_archivo;
    char nombre_archivo[] = "ejemplo.txt";
    
    // Abrir el archivo en modo lectura ("r") como ejemplo
    apuntador_archivo = fopen(nombre_archivo, "r");
    
    if (apuntador_archivo != NULL) 
    {   
        printf("El archivo se abrio correctamente.\n");
        // proceso; // Trabajo con el archivo
        fclose(apuntador_archivo);
        printf("El archivo se cerro correctamente.\n");
    }
    else
    {
        printf("No se puede abrir el archivo.\n");
    }
}