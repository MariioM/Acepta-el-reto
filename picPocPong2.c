#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int numeroSonidos, puntuacionIzq, puntuacionDer, lado;

    while (1)
    {
        puntuacionIzq = 0;
        puntuacionDer = 0;
        lado = 0;

        // Leer el número de sonidos
        scanf("%d", &numeroSonidos);

        if (numeroSonidos == 0)
        {
            break; // Si es 0, terminar el programa
        }

        // Asignar memoria dinámicamente para un array de punteros
        char **sonidos = (char **)malloc(numeroSonidos * sizeof(char *));
        for (int i = 0; i < numeroSonidos; i++)
        {
            sonidos[i] = (char *)malloc(6 * sizeof(char)); // Máximo 6 caracteres por sonido
        }

        // Leer los sonidos
        for (int i = 0; i < numeroSonidos; i++)
        {
            scanf("%s", sonidos[i]);

            if (strcmp(sonidos[i], "PIC") == 0)
            {
                lado = 1 - lado; // Cambiar el lado al escuchar "PIC"
            }
            else if (strcmp(sonidos[i], "PONG!") == 0)
            {
                if (lado == 0)
                {
                    puntuacionIzq++; // Punto para la izquierda
                }
                else
                {
                    puntuacionDer++; // Punto para la derecha
                }
                lado = 0; // Después de "PONG!" la bola siempre va hacia la derecha
            }
        }

        // Imprimir el marcador
        printf("%d %d\n", puntuacionIzq, puntuacionDer);

        // Liberar la memoria asignada para cada sonido
        for (int i = 0; i < numeroSonidos; i++)
        {
            free(sonidos[i]);
        }
        free(sonidos); // Liberar el array de punteros
    }

    return 0;
}
