#include <stdio.h>

void main() {
    // Estructura de datos simple para los 10 alumnos
    char nombres[10][20] = {"Juan", "Maria", "Pedro", "Ana", "Luis", "Elena", "Carlos", "Sofia", "Diego", "Lucia"};
    int edades[10] = {20, 21, 19, 22, 20, 23, 21, 20, 19, 22};

    // 1. Generar CSV
    FILE *fcsv = fopen("c:\\temp\\alumnos.csv", "w");
    for(int i = 0; i < 10; i++) fprintf(fcsv, "%s,%d\n", nombres[i], edades[i]);
    fclose(fcsv);

    // 2. Generar XML
    FILE *fxml = fopen("c:\\temp\\alumnos.xml", "w");
    fprintf(fxml, "<alumnos>\n");
    for(int i = 0; i < 10; i++) fprintf(fxml, "  <alumno><nombre>%s</nombre><edad>%d</edad></alumno>\n", nombres[i], edades[i]);
    fprintf(fxml, "</alumnos>");
    fclose(fxml);

    // 3. Generar JSON
    FILE *fjson = fopen("c:\\temp\\alumnos.json", "w");
    fprintf(fjson, "[\n");
    for(int i = 0; i < 10; i++) {
        fprintf(fjson, "  {\"nombre\": \"%s\", \"edad\": %d}%s\n", nombres[i], edades[i], (i < 9 ? "," : ""));
    }
    fprintf(fjson, "]");
    fclose(fjson);

    printf("Archivos generados exitosamente en c:\\temp\\\n");
}