#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int main()
{
    FILE *arquivo;

    char campo[65];
    char buffer[65];
    char *nomeCampos[] = {"sobrenome", "nome", "endereco", "cidade", "estado", "CEP"};

    int i, op = 1;
    while (op < 3)
    {
        printf("Menu\n1. Inserir um novo registro\n2. Buscar um registro por RRN para alterações\n3. Terminar o programa\nDigite o número da sua escolha: ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            for (i = 0; i < 6; i++)
            {
                printf("Informe o %s: ", nomeCampos[i]);
                input(campo, 42);
                strcat(buffer, campo);
                strcat(buffer, "|");
            }
            break;

        case 2:
            break;

        default:
            break;
        }
    }
}