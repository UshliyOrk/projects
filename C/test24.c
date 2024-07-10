#include <stdio.h>
#include <iso646.h>

int factorial(int n);
int fib(int n);
double power(double n, int p);
int gcd(int n, int m); //НОД алгоритм Евклида

int main (void)
{
    int p, x = 1;
    /*
    while (x)
    {
        printf("enter your number --> ");
        scanf("%d", &x);
        printf("%d! = %d\n", x, factorial(x));
    }
    */

/*
    while (x)
    {
        printf("enter your number --> ");
        scanf("%d %d", &x, &p);
        printf("%d^%d = %lf\n", x, p, power(x, p));
    }
*/

/*
    while (x)
    {
        printf("enter your number --> ");
        scanf("%d %d", &x, &p);
        printf("gcd (%d, %d) = %d\n", x, p, gcd(x, p));
    }
*/

    while (x)
    {
        printf("enter your number --> ");
        scanf("%d", &x);
        printf("fib(%d) = %d\n", x, fib(x));
    }
    return 0;
}

int factorial(int(n))
{
    if( n == 1 ) return 1;
    else if (n == 0) return 1;
    else if (n < 0) return -1;
    else return factorial(n-1)*n;
}

double power (double n, int p)
{
    if (n == 0 ) return 0;
    else if (p < 0) return -1;
    else if (n == 1 or p == 0) return 1;
    else
    {
        if (p%2 == 1) return power(n, p-1) * n;
        else return power(n*n, p/2);
    }
    
}

int gcd (int n, int m)
{
    if (0 == m) return n;
    return gcd(m, n%m);
}

int fib (int n)
{
    if (n <= 1) return n;
    else return fib(n-1)+fib(n-2);
}