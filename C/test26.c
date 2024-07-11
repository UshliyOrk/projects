// динамическое программирование
#include <stdio.h>
#include <iso646.h>
#include <time.h>

// статическая переменная живет вне функций
// static можно и не писать вроде бы, но желательно
static int cache[100] = {0};

//исходная функция для вычисления чисел фибоначи
int fib (int n)
{
    if (n <= 1) return n;
    else return fib(n-1)+fib(n-2);
}

//функция с кэшированием
//динамическое программирование снизу
int fib_cache (int n)
{
    if (n <= 1) return n;
    if (cache[n] == 0)  cache[n] = fib_cache(n-1)+fib_cache(n-2);
    return cache[n];
}

//динамическое программмирование сверху
int fib_dynamic(int n)
{
    int Fib[n+1];
    Fib[0] = 0;
    Fib[1] = 1;
    for (int i = 2; i <= n; i++) Fib[i] = Fib[i-1] + Fib[i-2];
    return Fib[n];
}

int main(void)
{
    for (int i = 30; i < 40; i++)
    {
        clock_t time1 = clock();
        int result = fib(i);
        clock_t time2 = clock();
        // время выполнения
        int delta_ms = (time2-time1)*1000/CLOCKS_PER_SEC;
        printf("fib(%d) = %d, \t time = %d ms\n", i,result, delta_ms);
    }


    for (int i = 30; i < 40; i++)
    {
        clock_t time1 = clock();
        int result = fib_cache(i);
        clock_t time2 = clock();
        // время выполнения
        int delta_ms = (time2-time1)*1000/CLOCKS_PER_SEC;
        printf("fib_cache(%d) = %d, \t time = %d ms\n", i,result, delta_ms);
    }

    for (int i = 30; i < 40; i++)
    {
        clock_t time1 = clock();
        int result = fib_dynamic(i);
        clock_t time2 = clock();
        // время выполнения
        int delta_ms = (time2-time1)*1000/CLOCKS_PER_SEC;
        printf("fib_dynamic(%d) = %d, \t time = %d ms\n", i,result, delta_ms);
    }
    
    return 0;
}
