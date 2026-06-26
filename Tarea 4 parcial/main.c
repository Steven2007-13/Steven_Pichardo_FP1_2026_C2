#include <stdio.h>
#include <stdlib.h>
#include <time.h> //le damos permiso al programa para abrir el reloj interno de la computadora

#define MAX_JUGADAS 40

int entrada(int jugadas[], float dinero[], int cantidad);
void salida(int jugadas[], float dinero[], int cantidad, int ganador);

int main()
{
    int opcion = 0;
    int opcion2 = 0;
    int cant_jugadas = 0;
    float dinero_jugado = 0.0;
    int numeros[MAX_JUGADAS];
    float dinero[MAX_JUGADAS];

    srand(time(NULL));//para sentar la base del generador aleatorio, en base a la hora actual

    do { // el menu
        printf("\n====== BANCA DE LOTERIA ======\n");
        printf("1. Jugar\n");
        printf("2. Salir\n");
        printf("==============================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        while(getchar()!='\n');

        switch(opcion)
        {
            case 1:
                printf("\n--- INICIANDO JUEGO ---\n");
                printf("\nPor favor ingrese el numero de jugadas (maximo 40): ");
                scanf("%i", &cant_jugadas);
                while(getchar()!='\n');
                if (cant_jugadas >  MAX_JUGADAS || cant_jugadas < 1)
                {
                    printf("\nDATO INCORRECTO!\n\n---- CERRANDO... ----\n");
                    return 0;
                }

                entrada(numeros, dinero, cant_jugadas);

                int num_ganador = (rand() % MAX_JUGADAS) + 1; //generamos el numero aleatorio con el resto de la division entre el numero maximo

                salida(numeros, dinero, cant_jugadas, num_ganador);

                printf("\nQuieres jugar denuevo?\n1-Si\n2-No\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &opcion2);
                while(getchar()!='\n');

                switch(opcion2)
                {
                case 1:
                    printf("\n---- Volviendo al menu... ----\n");
                    break;
                case 2:
                    printf("\n---- CERRANDO... ---\n");
                    return 0;
                default:
                    printf("\n---- DATO ERRONEO! REINICIANDO... ----\n");
                }

                break;

            case 2:
                printf("\n---- SALIENDO ----\n");
                break;

            default:
                printf("\nError! Opcion no valida. Intente de nuevo.\n");
        }

    } while(opcion != 2);

    return 0;
}

int entrada(int jugadas[], float dinero[], int cantidad)
{
    int i = 0;
    printf("\nIngrese los numeros a jugar (desde 1 a 40) \ny el dinero que apostara a cada uno (la ganancia del juego sera el dinero apostado por 1000)\n");
    for(i = 0; i < cantidad; i++)
    {
        printf("\nJugada %i: ", i+1);
        scanf("%i", &jugadas[i]);
        while(getchar()!='\n');
        if(jugadas[i] < 1 || jugadas[i] > MAX_JUGADAS)
        {
            printf("\n---- DATO INCORRECTO! ----\n\n---- VOLVIENDO AL MENU... ----\n");
            return 0;
        }
        printf("Monto %i: ", i+1);
        scanf("%f", &dinero[i]);
        while(getchar()!='\n');
        if(dinero[i] <= 0)
        {
            printf("\n---- DATO INCORRECTO! ----\n\n---- VOLVIENDO AL MENU... ----\n");
            return 0;
        }
    }
}

void salida(int jugadas[], float dinero[], int cantidad, int ganador)
{
    int j = 0;
    float premio = 0.0;
    printf("\n---- RESULTADOS DE LA LOTERIA ---\n");
    printf("\nEL NUMERO GANADOR ES...\n\n---- El %i ! ----\n\n", ganador);
    printf("Jugada\tApuesta\tDinero\tGanancia\n");
    for (j = 0; j < cantidad; j++)
    {
        if (jugadas[j] == ganador)
        {
            premio = dinero[j] * 1000;
        }
        else
        {
            premio = 0;
        }
        printf("\n%d\t%d\t%.2f\t%.2f\n", j+1, jugadas[j], dinero[j], premio);
    }
}
