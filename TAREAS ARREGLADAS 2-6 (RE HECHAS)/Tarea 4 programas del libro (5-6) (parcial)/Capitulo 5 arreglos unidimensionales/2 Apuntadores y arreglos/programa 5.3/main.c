#include <stdio.h>

void main(void)
{
    int X = 3, Y = 7, Z[5] = {2,4,6,8,10};
    printf("\nX = %d\tY = %d\tZ[0] = %d\tZ[1] = %d\tZ[2] = %d\tZ[3] = %d\tZ[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
    
    int *IX;
    IX = &X;
    Y = *IX;
    *IX = 1;
    printf("\nX = %d\tY = %d\tZ[0] = %d\tZ[1] = %d\tZ[2] = %d\tZ[3] = %d\tZ[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &Z[2];
    Y = *IX;
    *IX = 15;
    printf("\nX = %d\tY = %d\tZ[0] = %d\tZ[1] = %d\tZ[2] = %d\tZ[3] = %d\tZ[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *IX + 5;
    *IX = *IX - 5;
    printf("\nX = %d\tY = %d\tZ[0] = %d\tZ[1] = %d\tZ[2] = %d\tZ[3] = %d\tZ[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    ++*IX;
    *IX += 1;
    printf("\nX = %d\tY = %d\tZ[0] = %d\tZ[1] = %d\tZ[2] = %d\tZ[3] = %d\tZ[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *(IX + 1);
    printf("\nX = %d\tY = %d\tZ[0] = %d\tZ[1] = %d\tZ[2] = %d\tZ[3] = %d\tZ[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = IX + 1;
    Y = *IX;
    printf("\nX = %d\tY = %d\tZ[0] = %d\tZ[1] = %d\tZ[2] = %d\tZ[3] = %d\tZ[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = IX + 4;
    Y = *IX;
    printf("\nX = %d\tY = %d\tZ[0] = %d\tZ[1] = %d\tZ[2] = %d\tZ[3] = %d\tZ[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &X;
    IX = IX + 1;
    X = *IX;
    printf("\nX = %d\tY = %d\tZ[0] = %d\tZ[1] = %d\tZ[2] = %d\tZ[3] = %d\tZ[4] = %d", X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);
}