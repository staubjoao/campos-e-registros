#include<stdio.h>
#include<stdlib.h>

int leia(char str[], int size, FILE *entrada)
{
    int i=0;
    char c=fgetc(entrada);

    while(c!=EOF&&c!='|')
    {
        if(i<=size-1)
        {
            str[i]=c;
            i++;
        }
        c=fgetc(entrada);
    }
    str[i]='\0';
    return i;
}

int main()
{
    FILE *entrada;

    char nomeArq[20];
    char string[42];
    int cont=1;

    printf("Informe o nome do arquivo: ");
    scanf("%s", &nomeArq);
    entrada = fopen(nomeArq, "r");
    if(entrada==NULL)
        printf("O arquivo %s não pode ser aberto", nomeArq);
        return EXIT_FAILURE;

    while(leia(string, 20, entrada)>0)
    {
        printf("campo #%i: %s\n", cont, string);
        cont++;
    }

    fclose(entrada);
    return EXIT_SUCCESS;
}
