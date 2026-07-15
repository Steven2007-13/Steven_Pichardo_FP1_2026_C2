#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declaramos la cantidad de sorteos
#define SORTEOS 10000 

void generarYAnalizar() {
    // 1. Inicializamos la semilla con el tiempo para variar los resultados cada vez
    srand(time(NULL));

    // 2. Abrimos el archivo en modo escritura para guardar los resultados
    FILE *f = fopen("c:\\temp\\numero.json", "w");
    if (!f) return;

    // 3. Arreglo para registrar la frecuencia de cada numero del 0 al 100
    int frecuencias[101] = {0};

    fprintf(f, "[\n"); // Iniciamos la estructura del arreglo JSON
    
    for (int i = 0; i < SORTEOS; i++) {
        // 4. Generamos tres números aleatorios para cada sorteo
        int p = rand() % 101; 
        int s = rand() % 101;
        int t = rand() % 101;

        // 5. Incrementamos el contador correspondiente a cada número obtenido
        frecuencias[p]++; frecuencias[s]++; frecuencias[t]++;

        // 6. Escribimos el objeto en el archivo respetando el formato JSON
        fprintf(f, "  {\"Primera\": \"%d\", \"Segunda\": \"%d\", \"Tercera\": \"%d\"}%s\n", p, s, t, (i < SORTEOS - 1 ? "," : ""));
    }
    
    fprintf(f, "]"); // Finalizamos el arreglo JSON
    fclose(f); // Cerramos el archivo para liberar recursos
    printf("Archivo numero.json generado con %d sorteos.\n", SORTEOS);

    // 7. Algoritmo para encontrar los 3 números que más veces se repitieron
    printf("\n--- Resultados de la Loteria (3 mas repetidos) ---\n");
    for (int k = 0; k < 3; k++) {
        int max = 0, numMax = -1;
        
        // Recorremos el arreglo de frecuencias buscando el valor máximo actual
        for (int i = 0; i <= 100; i++) {
            if (frecuencias[i] > max) {
                max = frecuencias[i];
                numMax = i;
            }
        }
        
        // Imprimimos el resultado y ponemos a 0 esa frecuencia para encontrar el siguiente
        if (numMax != -1) {
            printf("%d. Numero %d (Aparecio %d veces)\n", k + 1, numMax, max);
            frecuencias[numMax] = 0; 
        }
    }
}

int main() {
    generarYAnalizar(); // Ejecución del proceso
    return 0;
}