#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>

double calc(double a, double b, const char* opt);
double power(double n, int p);

int main(void)
{
    double a=1, b;
    char *c;
    while (1){
        scanf("%lf %s %lf", &a, c, &b);
        if (a == 0) break;
        printf("%f %s %f = %f\n", a, c, b, calc(a, b, c));
    }
    printf("press ENTER to exit...");
    getchar();
    getchar();
    return 0;
}

double calc(double a, double b, const char* opt)
{
    if (not(strcmp(opt, "//"))) return (int)a/(int)b;
    else if (not(strcmp(opt, "+"))) return a+b;
    else if (not(strcmp(opt, "-"))) return a-b;
    else if (not(strcmp(opt, "*"))) return a*b;
    else if (not(strcmp(opt, "/"))) return a/b;
    else if (not(strcmp(opt, "%"))) return (int)a%(int)b;
    else if (not(strcmp(opt, "**"))) return power(a, b);
    else {
        printf("unknown option\n");
        exit(-1);
    }
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