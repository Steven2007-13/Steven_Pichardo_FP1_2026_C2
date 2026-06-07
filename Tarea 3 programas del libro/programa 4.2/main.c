#include <stdio.h>
#include <stdlib.h>

/* Conflicto de nombres.
El programa demuestra cómo se le da prioridad a las variables locales
sobre las globales cuando se llaman igual. */

/* Variables Globales */
int I = 10;

/* Prototipo de función */
void funcion1(void);

int main()
{
    printf("--- PROGRAMA 4.2: VARIABLES LOCALES Y GLOBALES ---\n\n");

    printf("En el main, la variable global I vale: %d\n", I);

    funcion1(); /* Llamada a la función */

    printf("De vuelta en el main, la variable global I sigue valiendo: %d\n", I);

    printf("\n");
    return 0;
}

void funcion1(void)
{
    /* Variable Local con el mismo nombre que la global */
    int I = 5;

    printf("Dentro de funcion1, la variable local I vale: %d (oculta a la global)\n", I);
}
