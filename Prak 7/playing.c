#include <stdio.h>
#include "stack.h"

int main()
{
    int n; scanf("%d", &n);
    char data[n][20];
    for(int i = 0; i < n; i++)
    {
        scanf("%s", data[i]);
    }
    Stack lagu; CreateEmpty(&lagu);
    int q; scanf("%d", &q);
    while (q--)
    {
        int x; scanf("%d", &x);
        if(x == 1)
        {
            int id; scanf("%d", &id);
            Push(&lagu, id);
            printf("Playing: %s\n", data[id]);
        }
        else
        {
            if(IsEmpty(lagu))
            {
                printf("No music is played\n");
            }
            else
            {
                int dump; Pop(&lagu, &dump);
                if(IsEmpty(lagu))
                {
                    printf("No music is played\n");
                }
                else
                {
                    printf("Playing: %s\n", data[Top(lagu)]);
                }
            }
        }
    }
}