#include<stdio.h>

int input(char str[], int size)
{
    int i=0;
    char c=getchar();

    while (c!='\n')
    {
        if(i<size-1)
        {
            str[i]=c;
            i++;
        }
        c=getchar();
    }
    str[i]='\0';
    return i;
}

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
    scanf("%s", &nomeArq);
    saida = fopen(nomeArq, "w");
    if(saida==NULL)
        printf("O arquivo %s não pode ser aberto", nomeArq);

    fflush(stdin);
    while(input(sobrenome, 20)>0)
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
}
