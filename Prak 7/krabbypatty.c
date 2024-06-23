#include "krabbypatty.h"

void krabbyPatty(Stack *ingredients, Stack *burger)
{
    Stack x; CreateEmpty(&x);
    int top = 0, bot = 0;
    while (!IsEmpty(*ingredients))
    {
        int cur; Pop(ingredients, &cur);
        if(cur == 0) bot = 1;
        else if(cur == 9) top = 1;
        else
        {
            Push(&x, cur);
        }

        if(top*bot) break;
    }
    if(top*bot)
    {
        Push(burger, 0);
        while (!IsEmpty(x))
        {
            int cur; Pop(&x, &cur);
            Push(burger, cur);
        }
        Push(burger, 9);
    }   
}