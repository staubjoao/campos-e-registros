#include "util.h"

int input(char str[], int size)
{
    int i = 0;
    char c = getchar();

    while (c != '\n')
    {
        if (i < size - 1)
        {
            str[i] = c;
            i++;
        }
        c = getchar();
    }
    str[i] = '\0';
    return i;
}

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