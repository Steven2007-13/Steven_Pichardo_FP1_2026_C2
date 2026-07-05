#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char cad[50];
    int res;
    FILE *ar;
    
    ar = fopen("c:\\temp\\arc.txt", "w");
    if (ar != NULL)  
    {
        printf("\nDesea ingresar una cadena de caracteres? Si-1 No-0: ");
        scanf("%d", &res);
        
        while (res)
        {
            while (getchar() != '\n');
            printf("Ingrese la cadena: ");
            fgets(cad, sizeof(cad), stdin);
            
            for (int j = 0; cad[j] != '\0'; j++) {
                if (cad[j] == '\n') { cad[j] = '\0'; break; }
            }
            
            fputs(cad, ar);   
            
            printf("\nDesea ingresar otra cadena de caracteres? Si-1 No-0: ");
            scanf("%d", &res);
            
            if (res) 
            {
                fputs("\n", ar);
            }
        }
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }
}