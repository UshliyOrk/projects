#include <stdio.h>
#include<inttypes.h>
int main(void)
{
    int8_t i = -128; /*знаковый шести битный инт*/
    unsigned int a =  10U; /*беззнаковый инт*/
    char c = 'Я'; /*знаковая переменная*/
    long long int z = i+a;/*не явное преобразование*/
    int d;
    printf("z = %lld\n", z);
    d = (int)c;/*явное преобразование идет переполнение*/
    printf("(int)c = %d\n", (int)c);
    i-=1;/*underflow*/
    printf("i = %d\n", i);
    i+=1;/*overflow*/
    printf("i = %d\n", i);
    return 0;
}