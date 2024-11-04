#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MIN_FOTO 3
#define MAX_PERSONAS 200000

struct personajes
{
    bool Mafalda;
    bool Felipe;
    bool Manolito;
    bool Susanita;
    bool Miguelito;
    bool Libertad;
    bool Guille;
    int numeroPersonas;
};

int main()
{
    while (1)
    {
        int numero_personas, i, j;
        int personas_foto = 0, numFotos = 0, numNoFotos = 0;
        scanf("%d", &numero_personas);
        char *personas[numero_personas];
        if (numero_personas == 0)
        {
            return 1;
        }
        for (i = 0; i < numero_personas; i++)
        {
            scanf("%s", personas[i]);
            personas_foto++;
            if (personas_foto >= 3)
            {
                if (strcmp(personas[i], "Mafalda") == 0)
                {
                    for (j = 0; j < i; j++)
                    {
                                        }
                }
            }
        }
    }
    return 0;
}