#include <stdio.h>
#include <math.h>

int main()
{
    int n; scanf("%d", &n);
    if(n <= 0) return 0;
    else if(n == 1) {int x; scanf("%d", &x); printf("%d\n", x); return 0;}
    int data[n];
    for(int i = 0; i < n; i++) scanf("%d", &data[i]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(data[j] > data[j+1])
            {
                int temp = data[j];
                data[j] = data[j+1]; data[j+1] = temp;
            }
        }
    }
    for(int i = n-1; i >= 0; i--)
    {
        if(i == 0) {printf("%d\n", data[0]); break;}
        if(data[i] != data[i-1]) {printf("%d\n", data[i-1]); break;}
    }
}

