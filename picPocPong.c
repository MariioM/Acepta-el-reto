#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    while (1)
    {
        int numeroSonidos, i, puntuacionIzq, puntuacionDer, lado; // Lado = 0 derecha, 1 Izquierda
        puntuacionIzq = 0;
        puntuacionDer = 0;
        lado = 0;
        char sonidos[6];
        // Entrada número sonidos
        scanf("%d", &numeroSonidos);
        if (numeroSonidos == 0)
        {
            break;
        }
        for (i = 0; i < numeroSonidos; i++)
        {
            scanf("%s", sonidos);
            if (strcmp("PIC", sonidos) == 0) // Un jugador le da
            {
                lado = 1 - lado;
            }
            else if (strcmp("PONG!", sonidos) == 0) // Gol
            {
                if (lado == 0)
                {
                    puntuacionIzq++; // Gol del jugador de la izquierda
                }
                else
                {
                    puntuacionDer++; // Gol del jugador de la derecha
                }
            }
        }
        printf("%d %d\n", puntuacionIzq, puntuacionDer);
    }
    return 0;
}