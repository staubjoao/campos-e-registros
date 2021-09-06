#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char buffer[134];
    char *campo;
    int cont = 1;

    printf("Informe o nome do arquivo: ");
    input(nomeArq, 20);
    entrada = fopen(nomeArq, "rb");
    if (entrada == NULL)
    {
        printf("O arquivo %s não pode ser aberto", nomeArq);
        return EXIT_FAILURE;
    }

    while ((leia(buffer, 134, entrada)) > 0)
    {
        campo = strtok(buffer, "|");
        while (campo != NULL)
        {
            printf("Campo %i: %s\n", cont, campo);
            cont++;
            campo = strtok(NULL, "|");
        }
        leia(buffer, 134, entrada);
    }

    fclose(entrada);
    return EXIT_SUCCESS;
}
