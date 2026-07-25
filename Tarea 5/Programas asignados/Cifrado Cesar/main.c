#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void codificar(char texto[], int llave);
void decodificar(char texto[], int llave);

void main(void)
{
    int opcion;
    char frase[100];
    int llave;

    do
    {
        printf("\n--- CIFRADO CESAR ---\n");
        printf("1. Codificar\n");
        printf("2. Decodificar\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 0)
        {
            break;
        }

        while (getchar() != '\n');

        printf("Ingrese la frase: ");
        fgets(frase, sizeof(frase), stdin);
        for (int j = 0; frase[j] != '\0'; j++) 
        {
            if (frase[j] == '\n') 
            { 
                frase[j] = '\0'; 
                break; 
            }
        }

        printf("Ingrese el numero llave (desplazamiento): ");
        scanf("%d", &llave);

        switch (opcion)
        {
            case 1:
                codificar(frase, llave);
                break;
            case 2:
                decodificar(frase, llave);
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } 
    while (opcion != 0);
    
    printf("\nFin del programa.\n");
}

void codificar(char texto[], int llave)
{
    int i;
    for (i = 0; texto[i] != '\0'; i++)
    {
        char c = texto[i];
        
        if (c >= 'a' && c <= 'z')
        {
            texto[i] = ((c - 'a' + llave) % 26) + 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            texto[i] = ((c - 'A' + llave) % 26) + 'A';
        }
    }
    printf("Frase codificada: %s\n", texto);
}

void decodificar(char texto[], int llave)
{
    int i;
    for (i = 0; texto[i] != '\0'; i++)
    {
        char c = texto[i];
        
        if (c >= 'a' && c <= 'z')
        {
            texto[i] = ((c - 'a' - llave + 26) % 26) + 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            texto[i] = ((c - 'A' - llave + 26) % 26) + 'A';
        }
    }
    printf("Frase decodificada: %s\n", texto);
}