#include <stdio.h>
#include <stdlib.h>


void init_array (int A[], int N)
{
    for (int i = 0; i<N; i++) A[i] = i;
}

int main(void)
{
    int N;
    printf("enter the size of an Array: ");
    scanf("%d", &N);
    int *A = (int *)malloc(N*sizeof(int)); //sizeof возращет размер типа
    if (NULL == A)//malloc вернет NULL если система не выделит память
    {
        printf("OS didn't gave memory. Exit...\n");
        exit(1);
    }
    // в таком случае максимальный размер будет ~100000000000000000 байт
    init_array(A, N);
    printf("Array A succesfylly created! \n");
    free(A); //освобождение выделенной памяти

    int *B = (int *)calloc(N, sizeof(int)); //calloc сам перемножает количество и тип данных и инициализирует массив
    if (NULL == B)
    {
        printf("OS didn't gave memory. Exit...\n");
        exit(1);
    }
    // в таком случае максимальный размер будет ~100000000000000000 байт
    init_array(B, N);
    printf("Array B succesfylly created! \n");
    free(B); //освобождение выделенной памяти


    system("pause");
    return 0;
}
/*
арифметика и сравнение работают только с указателями в одном сегменте памяти
если куски памяти аллоцированны в разные моменты времени, то с их указателями так рабоать нельзя
*/