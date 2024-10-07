#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int numeroSonidos, i, puntuacionIzq, puntuacionDer, lado; // Lado = 0 derecha, 1 Izquierda

    while (1)
    {
        puntuacionIzq = 0;
        puntuacionDer = 0;
        lado = 0;
        // Entrada número sonidos
        scanf("%d", &numeroSonidos);
        // Array Jugada
        char *sonidos[numeroSonidos];
        if (numeroSonidos == 0)
        {
            break;
        }
        for (i = 0; i < numeroSonidos; i++)
        {
            sonidos[i] = (char *)malloc(6 * sizeof(char));
            scanf("%s", sonidos[i]);
            if (strcmp("PIC", sonidos[i]) == 0) // Un jugador le da
            {
                lado = 1 - lado;
            }
            else if (strcmp("PONG!", sonidos[i]) == 0) // Gol
            {
                if (lado == 0)
                {
                    puntuacionIzq++; // Gol del jugador de la izquierda
                }
                else
                {
                    puntuacionDer++; // Gol del jugador de la derecha
                }
                lado = 0;
            }
        }
        printf("%d %d\n", puntuacionIzq, puntuacionDer);
        for (i = 0; i < numeroSonidos; i++)
        {
            free(sonidos[i]);
        }
    }
}