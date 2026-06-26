#include <stdio.h>
#include <stdlib.h>

/* Elección presidencial.
El programa procesa los votos de una elección para 5 candidatos y escribe
los resultados finales. */

int main()
{
    /* Usamos un vector de 6 posiciones para ignorar la casilla 0 y usar de la 1 a la 5 */
    int VOTOS[6] = {0};
    int VOTO, I;

    printf("--- PROGRAMA 5.2: CONTEO DE VOTOS ---\n\n");
    printf("Ingrese el numero del candidato (1 al 5). Digite 0 para terminar.\n\n");

    printf("Ingrese el primer voto: ");
    scanf("%d", &VOTO);
    while(getchar() !='\n');

    while (VOTO != 0)
    {
        if (VOTO >= 1 && VOTO <= 5)
        {
            VOTOS[VOTO]++; /* El voto se vuelve el índice y se incrementa 1 voto*/
        }
        else
        {
            printf("¡Voto nulo! Introduzca un candidato valido (1-5).\n");
        }

        printf("Ingrese el siguiente voto (0 para salir): ");
        scanf("%d", &VOTO);
        while(getchar() !='\n');
    }
    printf("\n--- RESULTADOS DE LA ELECCION ---\n");
    for (I = 1; I <= 5; I++)
    {
        printf("Candidato %d: %d votos\n", I, VOTOS[I]);
    }
    return 0;
}
