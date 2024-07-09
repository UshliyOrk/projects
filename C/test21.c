/*
работа с масивом через состояние заполненности
сортировка вставкой
*/
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
    int n;
    int A[100]; // массив создается не инициальзированным, нам не важно что там сейчас хранится
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
    printf("Unsorted array: \n");
    print_array(A, top);

//сорировка вставкой
    for (int i = 0; i<top; ++i)
    {
        for (int k = i+1; k<top; ++k)
        {
            int x = A[i];
            if (A[i] > A[k])
            {
                A[i] = A[k];
                A[k] = x;
            }
        }
    }

    printf("Sorted array: \n");
    print_array(A, top);
}
