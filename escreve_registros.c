#include<stdio.h>
#include<string.h>

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
    char campo[42];
    char buffer[134];
    int size;
    short num;
    char *nomeCampos[] = {"nome", "endereço", "cidade", "estado", "CEP"};

    printf("Informe o nome do arquivo: ");
    scanf("%s", &nomeArq);
    saida = fopen(nomeArq, "wb");
    if(saida==NULL)
        printf("O arquivo %s não pode ser aberto", nomeArq);


    printf("Informe o sobrenome: ");
    fflush(stdin);
    size = input(campo, 42);
    while(size>0)
    {
        buffer[0]= '\0';
        strcat(buffer, campo);
        strcat(buffer, "|");

        for(int i=0; i<5; i++)
        {
            printf("Informe o %s: ", nomeCampos[i]);
            input(campo, 42);
            strcat(buffer, campo);
            strcat(buffer, "|");
        }

        num=strlen(buffer);
        fwrite(&num, sizeof(short), 1, saida);
        fwrite(buffer, sizeof(char), num, saida);

        printf("Informe o sobrenome: ");
        size = input(campo, 42);
    }

    fclose(saida);
}
