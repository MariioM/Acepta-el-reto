#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // Se declara la variable del nº de fechas
    int numeroFechas, i;
    scanf("%d", &numeroFechas);
    char *fechas[numeroFechas];
    // Se almacenan las fechas indicadas
    for (i = 0; i < numeroFechas; i++)
    {
        fechas[i] = (char *)malloc(6 * sizeof(char));
        scanf(" %5[^\n]", fechas[i]);
        // Se comprueba si coincide con la fecha de navidad
        if (strcmp("25 12", fechas[i]) == 0)
        {
            printf("SI\n");
            free(fechas[i]); // Se libera memoria
        }
        else
        {
            printf("NO\n");
            free(fechas[i]); // Se libera memoria
        }
    }
    return 0;
}