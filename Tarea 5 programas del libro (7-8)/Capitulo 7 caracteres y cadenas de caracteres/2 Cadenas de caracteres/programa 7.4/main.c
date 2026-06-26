#include <stdio.h>

void main(void)
{
    char *cad0;
    
    cad0 = "Argentina";
    puts(cad0);
    
    cad0 = "Brasil";
    puts(cad0);

    char *cad1 = "";
    
    char cad2[20] = "Mexico";
    puts(cad2);
    
    fgets(cad2, sizeof(cad2), stdin);
    
    for(int i = 0; cad2[i] != '\0'; i++)
    {
        if(cad2[i] == '\n')
        {
            cad2[i] = '\0';
            break;
        }
    }
    
    puts(cad2);
}