#include <stdio.h>
#include <stdlib.h>

#define MATRIX_HEIGHT 4
#define MATRIX_WIDTH 5

void static_matrix_print(int A[][MATRIX_WIDTH], size_t N)
{
    for (int i = 0; i<N; i++){
        for (int j = 0; j<MATRIX_WIDTH; j++){ 
            printf("%*d", MATRIX_WIDTH, A[i][j]);
        }
        printf("\n");
    }
}

void static_matrix(size_t N)
{
    int A[N][MATRIX_WIDTH];
    int x = 1;
    for (int i = 0; i < N; i++){
        for (int j = 0; j<MATRIX_WIDTH; j++){
            A[i][j] = x;
            x+=1;
        }
    }
    static_matrix_print(A,N);

    printf("\nDirect memory acces:\n");
    for(int *p = (int *)A; p<(int *)A + MATRIX_HEIGHT*MATRIX_WIDTH; p++)
        printf("%3d", *p);
    printf("\n\n");
}

int** dynamic_matrix_allloc(size_t N, size_t M)
{
    int **A = (int **)malloc(N*sizeof(int*));
    for(int i=0; i<N; i++) A[i] = (int*)malloc(M*sizeof(int));
    return A;
}

void dynamic_matrix_free(int **A, size_t N)
{
    for (int i=0; i<N; i++) free(A[i]);
    free(A);
}

void dynamic_matrix_print(int **A, size_t N, size_t M)
{
    for(int i = 0; i<N; i++){
        for (int j =0; j<M; j++) printf("%*d", M, A[i][j]);
        printf("\n");
    }
}

void dynamic_matrix(size_t N, size_t M)
{
    int **A = dynamic_matrix_allloc(N, M);
    int x = 1;
    for (int i = 0; i<N; i++){
        for (int j = 0; j<M; j++){
            A[i][j] = x;
            x+=1;
        }
    }
    dynamic_matrix_print(A,N,M);
    dynamic_matrix_free(A,N);
}

int main(void)
{
    //static_matrix(MATRIX_HEIGHT);
    int matrix_hieght = 4;
    int matrix_width = 5;
    dynamic_matrix(matrix_hieght, matrix_width);
    return 0;
}


/*
статическая матрица должна иметь константную ширину
все элменты матрици в таком случе по сути идут подряд на самом деле
змейкой такой, если представлять визуально

для динамической матрици создается массив указателей размера N
в последсвии по каждому из указтелей создается массив размера M
память соответсвенно нужно осовобожать последовательно, сначала указатели из масиива указателей
затем сам массив указателей

этот способ ресурсоемкий из-за множественного обращения к системе, как для создания, так и для удаления
но это позволяет указывать размер массива переменными
то есть его, например, можно ввести с клавиатуры полностью, в отличие от статического
*/