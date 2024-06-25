#include <stdio.h>
#include<math.h>

int main(void)
{
    int m = -32768;
    while (1)
    {
        int x;
        scanf("%d", &x);
        if (x==0) break;
        m = (x > m) ? x:m;
    }
    printf("max = %d\n", m);
    
    return 0;
}