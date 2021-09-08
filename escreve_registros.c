#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

int main()
{
    FILE *saida;

    char nomeArq[20];
    char campo[42];
    char buffer[134];
    int size, i;
    short num;
    char *nomeCampos[] = {"sobrenome", "nome", "endereco", "cidade", "estado", "CEP"};

    printf("Informe o nome do arquivo: ");
    input(nomeArq, 20);
    saida = fopen(nomeArq, "wb");
    if (saida == NULL)
    {
        printf("O arquivo %s nao pode ser aberto", nomeArq);
        return EXIT_FAILURE;
    }

    printf("Informe o sobrenome: ");
    fflush(stdin);
    size = input(campo, 42);
    while (size > 0)
    {
        buffer[0] = '\0';
        strcat(buffer, campo);
        strcat(buffer, "|");

        for (i = 0; i < 6; i++)
        {
            printf("Informe o %s: ", nomeCampos[i]);
            input(campo, 42);
            strcat(buffer, campo);
            strcat(buffer, "|");
        }

        num = strlen(buffer);
        fwrite(&num, sizeof(short), 1, saida);
        fwrite(buffer, sizeof(char), num, saida);

        printf("Informe o sobrenome: ");
        size = input(campo, 42);
    }

    fclose(saida);
    return EXIT_SUCCESS;
}
