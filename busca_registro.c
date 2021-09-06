#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"

int leia(char buffer[], int size, FILE *entrada)
{
    int i = 0;
    short num;
    fread(&num, sizeof(short), 1, entrada);

    if (feof(entrada) != 0)
        return 0;
    if (num < size)
    {
        fread(buffer, sizeof(char), num, entrada);
        buffer[num] = '\0';
        return num;
    }
    else
        return 0;
}

int main()
{
    FILE *entrada;
    char nomeArq[20];
    char sobrenome[20];
    char buffer[134];
    bool achou = false;

    printf("Informe o nome do arquivo: ");
    input(nomeArq, 20);
    entrada = fopen(nomeArq, "rb");
    if (entrada == NULL)
    {
        printf("O arquivo %s não pode ser aberto", nomeArq);
        return EXIT_FAILURE;
    }

    printf("Informe o sobrenome que deseja buscar: ");
    input(sobrenome, 20);
}