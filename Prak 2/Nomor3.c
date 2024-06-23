#include <stdio.h>
#include <math.h>

int armstrong(int x)
{
    int n = floor(log10(x)) + 1;
    int current = x, result = 0;
    while(current)
    {
        result += round(pow((current%10), n));
        if(result > x) return 0;
        current /= 10;
    }
    return (result == x);
}

int main()
{
    int x, y; scanf("%d %d", &x, &y);
    for(int i = x; i <= y; i++)
    {
        if(armstrong(i)) printf("%d\n", i);
    }
}