// копирование, реверс и циклический сдвиг
#include <stdio.h>
#define N 10

void print_array(int arr[])
{
    for(int i = 0; i<N; ++i) printf("%3d", arr[i]);
    printf("\n");
}

int main(void)
{
    int a[N] = {0, 5, 10, 15, 20, 25,
                30, 35, 40, 45};
    int b[N] = {0};

    for (int i = 0; i < N; i++)
    {
        b[i] = a[i]; // копирование
        b[i] = a[N-i-1]; // реверсивное копирование
    }

    print_array(a);
    print_array(b);

    printf("\n");
    // реверс массива а
    for (int i = 0; i < N/2; i++)
    {
        int tmp = a[i];
        a[i] = a[N-i-1];
        a[N-i-1] = tmp;
    }
    print_array(a);

    //сдвиг
    int tmp = a[0];
    for (int i = 0; i < N-1; i++)
    {
        a[i] = a[i+1]; // влево
    }
    a[N-1] = tmp;
    print_array(a);

    tmp = a[N-1];
    for (int i = N-1; i > 0; i--)
    {
        a[i] = a[i-1]; // вправо
    }
    a[0] = tmp;
    print_array(a);
    
    return 0;
}