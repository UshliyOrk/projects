/*
сортировка по счетчику
имеетлинейную скорость исполнения
*/
#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <time.h>
#define NC 21 //количество ключей от нуля до NC-1

void print_array(int arr[], int N)
{
    for(int i = 0; i<N; ++i) printf("%3d", arr[i]);
    printf("\n");
}

int main (void)
{
    int N;
    printf("enter the number of elements --> ");
    scanf("%d", &N);
    int A[N];// неотсортированный массив который будет содержать только 10 ключей
    int counters[NC] = {0};// счетчик ключей

    srand(time(NULL));

    for (int i = 0; i < N; i++) A[i] = rand()%NC;
    
    printf("unsorted array: \n");
    print_array(A, N);

    // сортировка

    // частотный анализ
    for (int i = 0; i < N; i++)
    {   
        counters[A[i]] += 1;//считаем количество входов
    }

    printf("counters: \n");
    for (int i = 0; i < NC; i++) printf("%3d", i);
    printf("\n");
    print_array(counters, NC);

    //вывод по возрастанию

    printf("sorted array: \n");
    for (int i = 0; i < NC; i++)
    {
        for (int k = 0; k < counters[i]; k++)
        {
            printf("%3d", i);
        }
    }
    printf("\n");
    
    //вывод по убыванию
    printf("sorted array: \n");
        for (int i = NC-1; i >= 0; i--)
    {
        for (int k = 0; k < counters[i]; k++)
        {
            printf("%3d", i);
        }
    }
    printf("\n");

    return 0;
}