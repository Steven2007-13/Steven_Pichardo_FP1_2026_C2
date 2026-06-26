#include <stdio.h>

void main(void)
{
    float P, S, R;
    printf("\nIngrese las ventas de los tres vendedores: ");
    scanf("%f %f %f", &P, &S, &R);
    if (P > S)
        if (P > R)
            if (S > R)
                printf("\n\nEl roden es P, S, R: %8.2f, %8.2f, %8.2f", P, S, R);
            else
                printf("\n\nEl roden es P, R, S: %8.2f, %8.2f, %8.2f", P, R, S);
        else
            printf("\n\nEl roden es R, P, S: %8.2f, %8.2f, %8.2f", R, P, S);
    else
        if (S > R)
            if (P > R)
                printf("\n\nEl roden es S, P, R: %8.2f, %8.2f, %8.2f", S, P, R);
            else
                printf("\n\nEl roden es S, R, P: %8.2f, %8.2f, %8.2f", S, R, P);
        else
            printf("\n\nEl roden es R, S, P: %8.2f, %8.2f, %8.2f", R, S, P);
}