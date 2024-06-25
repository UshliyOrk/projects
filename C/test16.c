#include<stdio.h>
#define N 10
int main(void)
{
    int a[6] = {1,2,3};
    int b[N];

    for(int i = 0; i < N; ++i)
    {
        b[i] = i;
    }

    for(int i = 0; i < N; ++i)
    {
        printf("%d ",b[i]);
    }

    printf("\n");

    for(int i = 0; i < 6; ++i)
    {
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;
}