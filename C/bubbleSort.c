#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>

void bubbleSort(int arr[], size_t N);
void print_array(int arr[], size_t N, int M);

int main(void)
{
    int N;
    printf("enter the number of elements--> ");
    scanf("%d", &N);
    int A[N];
    srand(time(NULL));
    for (int i = 0; i<N; i++){
        A[i] = rand()%100;
    }

    print_array(A, N, 10);
    printf("\n");
    bubbleSort(A, N);
    print_array(A, N, 10);

    return 0;
}

void bubbleSort(int arr[], size_t N)
{
    for (int i = 0; i<N-1; i++){
        for (int j = 0; j<N-i-1; j++)
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
    }
}

void print_array(int arr[], size_t N, int M)
{
        for (int i = 0; i<N; i++){
        if (i%M == 0 and i != 0) printf("\n");
        printf("%3d ", arr[i]);
    }
    printf("\n");
}