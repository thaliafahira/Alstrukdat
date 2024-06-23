#include <stdio.h>

int  main()
{
    int n; scanf("%d", &n);
    if(n < 1 || n > 50) printf("%d\n", -1);
    else
    {
        int order = 3, ans = 0;
        int first = 1, second = 1; n -= 2;
        while(n > 0)
        {
            int current = first + second;
            if(order%3 == 0) ans += current;
            first = second ; second = current;
            order++; n--;
        }
        printf("%d\n", ans);
    }
}

