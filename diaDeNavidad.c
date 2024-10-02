#include <stdio.h>
#include <string.h>

int main()
{
    // Se declara la variable del nº de fechas
    int numeroFechas;
    printf("Indique el numero de fechas a consultar: ");
    scanf("%d", &numeroFechas);
    char fechas[numeroFechas][5];
    for (int i = 0; i < numeroFechas; i++)
    {
        printf("Indique la %dº fecha: ", i + 1);
        scanf("%s", fechas[i]);
        fflush(stdin);
    }
    for (int i = 0; i < numeroFechas; i++)
    {
        printf("%s\n", fechas[i]);
    }
    scanf("%d", &numeroFechas);
    return 0;
}