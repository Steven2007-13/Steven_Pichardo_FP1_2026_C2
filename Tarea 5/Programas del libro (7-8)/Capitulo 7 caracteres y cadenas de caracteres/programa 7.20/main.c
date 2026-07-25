#include <stdio.h>
#include <string.h>

int longitud(char *cadena);

void main(void)
{
    int i, n, l = -1, p, t;
    char cad[50], FRA[20][50];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);

    while (getchar() != '\n');

    for(i = 0; i < n; i++)
    {
        printf("Ingrese la linea %d de texto: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Quitar el salto de línea que agrega fgets
        for (int j = 0; FRA[i][j] != '\0'; j++)
        {
            if (FRA[i][j] == '\n')
            {
                FRA[i][j] = '\0';
                break;
            }
        }
        
        t = longitud(FRA[i]);
        
        if (t > l)
        {
            l = t;
            p = i;
        }
    }

    printf("\nLa cadena con mayor longitud es: ");
    puts(FRA[p]);
    printf("\nLongitud: %d\n", l);
}

int longitud(char *cadena)
{
    int cue = 0;
    while(cadena[cue] != '\0')
    {
        cue++;
    }
    
    return (cue);
}