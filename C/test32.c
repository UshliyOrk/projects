#include <stdio.h>
#include <stdlib.h>

void pause(void)
{
    printf("press ENTER to continue. . .");
    int c = getchar();
}

void init_array (char A[], int N)
{
    for (int i = 0; i<N; i++) A[i] = i+66;
}

void print_array(char arr[], int N)
{
    for(int i = 0; i<N; ++i) printf("%c ", arr[i]);
    printf("\n");
}

int main(void)
{
    printf("enter the size of an Array: ");
    int N;
    scanf("%d", &N);
    char A[N]; //char весит 1 байт
    // для нынешней конфигурации максимальный размер массива ~2050000 байт
    init_array(A, N);
    printf("Array A succesfylly created! \n");

    // выделение памяти вручную
    printf("enter the size of an Array: ");
    scanf("%d", &N);
    char *B = (char *)malloc(N); //выделение памяти malloc - memory allocate
    if (NULL == B)//malloc вернет NULL если система не выделит память
    {
        printf("OS didn't gave memory. Exit...\n");
        exit(1);
    }
    // в таком случае максимальный размер будет ~100000000000000000 байт
    init_array(B, N);
    printf("Array B succesfylly created! \n");

    system("pause");
    return 0;
}