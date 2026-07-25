#include <stdio.h>
#include <string.h>

void procesarCSV(const char *ruta);
void procesarXML(const char *ruta);
void procesarJSON(const char *ruta);

int main() {
    char ruta[100];
    printf("Ingrese la ruta del archivo (ej. c:\\temp\\archivo.csv): ");
    scanf("%s", ruta);

    if (strstr(ruta, ".csv")) {
        procesarCSV(ruta);
    } else if (strstr(ruta, ".xml")) {
        procesarXML(ruta);
    } else if (strstr(ruta, ".json")) {
        procesarJSON(ruta);
    } else {
        printf("Formato no soportado.\n");
    }
    return 0;
}

void procesarCSV(const char *ruta) {
    FILE *f = fopen(ruta, "r");
    if (!f) { printf("Error al abrir.\n"); return; }
    
    printf("\n--- Tabla CSV ---\n%-15s | %-15s | %-10s\n-------------------------------------------\n", "Nombre", "Apellido", "Edad");
    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        linea[strcspn(linea, "\n")] = 0;
        // Busca separedores de coma y extrae los valores
        char *n = strtok(linea, ",");
        char *a = strtok(NULL, ",");
        char *e = strtok(NULL, ",");
        if (n && a && e) printf("%-15s | %-15s | %-10s\n", n, a, e);
    }
    fclose(f);
}

void procesarXML(const char *ruta) {
    FILE *f = fopen(ruta, "r");
    if (!f) { printf("Error al abrir.\n"); return; }
    
    printf("\n--- Procesando XML (Valores encontrados) ---\n");
    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        // Busca etiquetas simples como <nombre>valor</nombre>
        char *inicio = strstr(linea, ">");
        char *fin = strstr(linea, "</");
        if (inicio && fin && fin > inicio) {
            *fin = '\0';
            printf("Dato: %s\n", inicio + 1);
        }
    }
    fclose(f);
}

void procesarJSON(const char *ruta) {
    FILE *f = fopen(ruta, "r");
    if (!f) { printf("Error al abrir.\n"); return; }
    
    printf("\n--- Procesando JSON (Valores encontrados) ---\n");
    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        // Busca después de los dos puntos en pares "llave": "valor"
        char *inicio = strchr(linea, ':');
        if (inicio) {
            printf("Dato: %s\n", inicio + 1);
        }
    }
    fclose(f);
}