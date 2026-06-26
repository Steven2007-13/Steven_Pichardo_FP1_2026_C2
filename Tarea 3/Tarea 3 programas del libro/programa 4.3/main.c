#include <stdio.h>
#include <stdlib.h>

/* Conflicto entre los nombres de las variables. */

/* Variable Global */
int I = 5;

/* Prototipo de función */
void f1(void);

int main()
{
    int I = 7; /* Variable local al main */

    printf("--- PROGRAMA 4.3: variables de cada casa ---\n\n");
    printf("Local de main I: %d\n", I);

    f1();

    printf("\n");
    return 0;
}

void f1(void)
{
    int K = 2;
    K += K;
    printf("El valor de la variable local K es: %d\n", K);

    I = I + K;
    printf("El valor de la variable global modificada es: %d\n", I);
}
