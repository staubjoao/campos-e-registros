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