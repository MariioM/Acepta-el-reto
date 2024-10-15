#include <stdio.h>
#include <string.h>

#define MAX_CANCIONES 30
#define MAX_DURACION 1000

typedef struct cancion
{
    int duracion, puntuacion;
} cancion;

int MaxPuntuacionTotal(cancion canciones[], int numeroCanciones, int duracionCara1, int duracionCara2)
{
    // Array con la puntuación máxima [primera cara] [segunda cara]
    int puntuacionMaxima[MAX_DURACION + 1][MAX_DURACION + 1] = {0};
    int i, j, k;
    // Se recorren todas las canciones
    for (i = 0; i < numeroCanciones; i++)
    {
        // Se recorre los tiempos posibles de la cara 1
        for (j = duracionCara1; j >= 0; j--)
        {
            // Se recorre los tiempos posibles de la cara 2
            for (k = duracionCara2; k >= 0; k--)
            {
                if (j >= canciones[i].duracion) // Si la canción cabe en la cara, se comprueba si es optimo
                {
                    // Se compara la puntuación actual con la que se pondría ahora
                    if (puntuacionMaxima[j][k] < puntuacionMaxima[j - canciones[i].duracion][k] + canciones[i].puntuacion)
                    {
                        puntuacionMaxima[j][k] = puntuacionMaxima[j - canciones[i].duracion][k] + canciones[i].puntuacion;
                    }
                }
                if (k >= canciones[i].duracion)
                {
                    if (puntuacionMaxima[j][k] < puntuacionMaxima[j][k - canciones[i].duracion] + canciones[i].puntuacion)
                    {
                        puntuacionMaxima[j][k] = puntuacionMaxima[j][k - canciones[i].duracion] + canciones[i].puntuacion;
                    }
                }
            }
        }
    }

    return puntuacionMaxima[duracionCara1][duracionCara2];
}

int main()
{
    int numeroCanciones, duracionCara, maxPuntuacionTotal, i;
    cancion canciones[MAX_CANCIONES];

    while (1)
    {
        // Se pide el numero de canciones
        scanf("%d", &numeroCanciones);
        if (numeroCanciones == 0)
            break;
        // Se pide la duración de las caras
        scanf("%d", &duracionCara);
        // Se rellenan las canciones
        for (i = 0; i < numeroCanciones; i++)
        {
            scanf("%d %d", &canciones[i].duracion, &canciones[i].puntuacion);
        }

        maxPuntuacionTotal = MaxPuntuacionTotal(canciones, numeroCanciones, duracionCara, duracionCara);

        printf("%d\n", maxPuntuacionTotal);
    }

    return 0;
}