#include <stdio.h>
#include <stdlib.h>

typedef struct                 
{
    int clave;
    char nombre[20];
    int carrera;
    float promedio;
    float examen;
    char telefono[12];
} alumno;

float F1(FILE *);
void F2(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *);
void F3(FILE *, FILE *, FILE *, FILE *, FILE *);  

void main(void)
{
    float pro;
    FILE *ap, *c1, *c2, *c3, *c4, *c5;
    
    ap = fopen("c:\\temp\\alu1.dat", "r");
    c1 = fopen("c:\\temp\\car1.dat", "w+");
    c2 = fopen("c:\\temp\\car2.dat", "w+");
    c3 = fopen("c:\\temp\\car3.dat", "w+");
    c4 = fopen("c:\\temp\\car4.dat", "w+");
    c5 = fopen("c:\\temp\\car5.dat", "w+");
    
    if ((ap != NULL) && (c1 != NULL) && (c2 != NULL) && (c3 != NULL) &&
        (c4 != NULL) && (c5 != NULL))
    {
        pro = F1(ap);
        printf("\nPROMEDIO EXAMEN DE ADMISION: %.2f\n", pro);
        F2(ap, c1, c2, c3, c4, c5);
        F3(c1, c2, c3, c4, c5);
    }
    else
    {
        printf("\nEl o los archivos no se pudieron abrir\n");
    }
    
    if (ap) fclose(ap);
    if (c1) fclose(c1);
    if (c2) fclose(c2);
    if (c3) fclose(c3);
    if (c4) fclose(c4);
    if (c5) fclose(c5);
}

float F1(FILE *ap)
{
    alumno alu;
    float sum = 0, pro;
    int i = 0;
    
    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap))
    {
        i++;
        sum += alu.examen;
        fread(&alu, sizeof(alumno), 1, ap);
    }
    pro = (i == 0) ? 0 : (sum / i);
    return (pro);
}

void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    alumno alu;
    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap))
    {
        if (((alu.examen >= 1300) && (alu.promedio >= 8)) || ((alu.examen >= 1400) && (alu.promedio >= 7)))
        {
            switch (alu.carrera)
            {
                case 1: fwrite(&alu, sizeof(alumno), 1, c1); break;
                case 2: fwrite(&alu, sizeof(alumno), 1, c2); break;
                case 3: fwrite(&alu, sizeof(alumno), 1, c3); break;
                case 4: fwrite(&alu, sizeof(alumno), 1, c4); break;
                case 5: fwrite(&alu, sizeof(alumno), 1, c5); break;
            }
        }
        fread(&alu, sizeof(alumno), 1, ap);
    }
}

void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    alumno alu;
    float cal[5], sum;
    int i, j; 
    FILE *archivos[5] = {c1, c2, c3, c4, c5};

    for (j = 0; j < 5; j++)
    {
        sum = 0;
        i = 0;
        rewind(archivos[j]);
        fread(&alu, sizeof(alumno), 1, archivos[j]);
        while (!feof(archivos[j]))
        {
            i++;
            sum += alu.examen;
            fread(&alu, sizeof(alumno), 1, archivos[j]);
        }
        cal[j] = (i != 0) ? (sum / i) : 0;
    }

    for (i = 0; i < 5; i++)
        printf("\nPromedio carrera %d: %.2f", i + 1, cal[i]);
    printf("\n");
}