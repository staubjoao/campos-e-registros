#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int main()
{
    FILE *entrada;
    char nomeArq[20];
    char sobrenomeBusca[20];
    char *sobrenome;
    char *campo;
    int cont = 1;
    char buffer[134];
    int achou = 0;
    int compReg;
    printf("Informe o nome do arquivo: ");
    input(nomeArq, 20);
    entrada = fopen(nomeArq, "rb");
    if (entrada == NULL)
    {
        printf("O arquivo %s não pode ser aberto", nomeArq);
        return EXIT_FAILURE;
    }
    compReg = leia(buffer, 134, entrada);

    printf("Informe o sobrenome que deseja buscar: ");
    input(sobrenomeBusca, 20);

    while (achou == 0 && compReg > 0)
    {
        sobrenome = strtok(buffer, "|");
        if (strcmp(sobrenome, sobrenomeBusca) == 1)
        {
            achou = 1;
        }
        else
        {
            compReg = leia(buffer, 134, entrada);
        }
    }

    if (achou == 1)
    {
        printf("%s: \n", sobrenome);
        campo = strtok(buffer, "|");
        while (campo != NULL)
        {
            printf("Campo %i: %s\n", cont++, campo);
            campo = strtok(NULL, "|");
        }
        leia(buffer, 134, entrada);
    }

    fclose(entrada);
    return EXIT_SUCCESS;
}