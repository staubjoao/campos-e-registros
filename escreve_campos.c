#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
    FILE *saida;

    char nomeArq[20];
    char sobrenome[20];
    char nome[20];
    char rua[42];
    char cidade[42];
    char uf[3];
    char cep[9];

    printf("Informe o nome do arquivo: ");
    input(nomeArq, 20);
    saida = fopen(nomeArq, "w");
    if (saida == NULL)
    {
        printf("O arquivo %s não pode ser aberto", nomeArq);
        return EXIT_FAILURE;
    }

    while (input(sobrenome, 20) > 0)
    {
        fputs(sobrenome, saida);
        fputs("|", saida);
        printf("nome\n");
        input(nome, 20);
        fputs(nome, saida);
        fputs("|", saida);
        printf("rua\n");
        input(rua, 42);
        fputs(rua, saida);
        fputs("|", saida);
        printf("cidade\n");
        input(cidade, 42);
        fputs(cidade, saida);
        fputs("|", saida);
        printf("uf\n");
        input(uf, 3);
        fputs(uf, saida);
        fputs("|", saida);
        printf("cep\n");
        input(cep, 9);
        fputs(cep, saida);
        fputs("|", saida);
    }
    fclose(saida);

    return EXIT_SUCCESS;
}
