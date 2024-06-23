#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

int main()
{
    char vokal[] = {'a', 'i', 'u', 'e', 'o'};
    char exception;
    scanf("%c", &exception);

    int count = 0;

    START();
    while (!EOP)
    {
        if (GetCC() == exception)
        {
            ADV();
            continue;
        }
        for (int i = 0; i < 5; i++)
        {
            if (GetCC() == vokal[i])
            {
                printf("%c", vokal[i]);
                count++;
            }
        }
        ADV();
    }
    if (count != 0)
    {
        printf(" ");
    }

    printf("%d\n", count);
}