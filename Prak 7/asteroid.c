#include <stdio.h>
#include <math.h>
#include "asteroid.h"

boolean isCollision(infotype a, infotype b)
{return (a>0)&&(b<0);}

void collision(int n, infotype *asteroids, Stack *remaining)
{
    Push(remaining, asteroids[0]);
    for(int i = 1; i < n; i++)
    {
        if(!isCollision(InfoTop(*remaining), asteroids[i])) Push(remaining, asteroids[i]);
        else
        {
            int push = 0;
            while (isCollision(InfoTop(*remaining), asteroids[i]) && !IsEmpty(*remaining))
            {
                int x = abs(InfoTop(*remaining));
                int y = abs(asteroids[i]);
                
                if(x > y) break;
                else if(x < y)
                {
                    int dump; Pop(remaining, &dump);
                    push = 1;
                }   
                else
                {
                    int dump; Pop(remaining, &dump);
                    break;
                }
            }
            if(push) Push(remaining, asteroids[i]);
        }
    }
}

void displayAsteroids(Stack S)
{
    if(IsEmpty(S))
    {
        printf("[]\n");
        return;
    }
    Stack copy; CreateEmpty(&copy);
    while (!IsEmpty(S))
    {
        int cur; Pop(&S, &cur);
        Push(&copy, cur);
    }
    printf("[");
    int dump; Pop(&copy, &dump);
    printf("%d", dump);
    while (!IsEmpty(copy))
    {
        Pop(&copy, &dump);
        printf(",%d", dump);
    }
    printf("]\n");
}