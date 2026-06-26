#include <stdio.h>

void main(void)
{
    int ELE[5] = {0};
    int I, VOT;

    printf("\nIngresa el primer voto (0 - para terminar): ");
    scanf("%d", &VOT);

    while(VOT)
    {
        if((VOT > 0) && (VOT < 6))
        {
            ELE[VOT-1]++;
        }
        else
        {
            printf("\nEl voto ingresado es incorrecto.\n");

        }
        printf("\nIngresa el siguiente voto (0 - para terminar): ");
        scanf("%d", &VOT);
    }
    printf("\n\nReultados de la eleccion\n");
    for (I = 0; I < 5; I++)
    {
        printf("\nCandidato %d: %d votos", I+1, ELE[I]);
    }
}