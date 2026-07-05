#include <stdio.h>
#include <stdlib.h>

int cuenta(char);                

void main(void)
{
    int res;
    char car;
    
    printf("\nIngrese el caracter que se va a buscar en el archivo: ");
    car = getchar();
    
    res = cuenta(car);
    
    if (res != -1)
    {
        printf("\n\nEl caracter %c se encuentra en el archivo %d veces\n", car, res);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }
}

int cuenta(char car)
{
    int res, con = 0;
    char p;
    FILE *ar;
    
    ar = fopen("c:\\temp\\arc.txt", "r");
    
    if (ar != NULL)    
    {
        p = fgetc(ar);
        while (!feof(ar))    
        {
            if (p == car)   
            {
                con++;
            }
            p = fgetc(ar);
        }
        
        fclose(ar);
        res = con; 
    }
    else
    {
        res = -1;
    }
    
    return (res);
}