#include <stdio.h>
#include <stdlib.h> // rand (0 -> MAX_RAND == 32767)
#include <time.h>

void print_array(int arr[], int N)
{
    for(int i = 0; i<N; ++i) printf("%d ", arr[i]);
    printf("\n");
}


int main(void)
{
    // реализация стека
    int LEN, n; // максимальная длинна массива
    scanf("%d", &LEN);
    int A[LEN]; // массив создается не инициальзированным, нам не важно что там сейчас хранится
    int top = 0; // состояние заполненности массива

    srand(time(NULL));
/*
srand - инициализация генератора случайных чисел принимает число
time - при передаче NULL возвращает количество секунд с 01.01.1970
*/

    printf("enter the number of elements --> ");
    scanf("%d", &n);

    for(int i = 0; i<n; ++i)
    {
        //push
        A[i] = rand();
        top ++;
    }
    print_array(A, top);

    for(int i = 0; i<top; ++i)
    {
        //pop
        printf("%d\n", A[i]);
        top -=1;
    }

    return 0;
}