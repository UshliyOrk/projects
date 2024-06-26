#include <stdio.h>
#include<iso646.h>
#define N 100

int main (void)
{
    int sieve[N] = {0};

    for(int i = 2; i*i < N; ++i)
    {
        for(int k = i*i; k<N; k += i) sieve[k] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        if(not(sieve[i])) printf("%3d", i); // вырванивание в три символа
    }

    printf("\n");
    
    return 0;
}