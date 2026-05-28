#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota = 0.0;
    float suma_notas= 0.0;
    float promedio = 0.0;
    int contador_notas = 0;
    int respuesta = 0;

    printf("--- Calculadora de Promedios Academicos ---\n");
    do
    {
        printf("\nIngrese una calificacion: ");
        scanf("%f", &nota);
        while(getchar() !='\n');
        suma_notas += nota;
        contador_notas++;
        printf("\n\nDesea registrar otra nota? (1-Si / 2-No): ");
        scanf("%i", &respuesta);
        while(getchar() !='\n');
    }while (respuesta == 1);
    if (contador_notas > 0)
    {
        promedio = suma_notas/contador_notas;
        printf("\n\n--- Resultado Final---\n");
        printf("\nTotal de notas registradas: %i",contador_notas);
        printf("\nPromedio final de la materia: %.2f",promedio);
    }else{printf("\n\nNo se registraron calificaciones.\n");}
    return 0;
}
