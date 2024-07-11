#include <stdio.h>

//количество траекторий для кузнечика из точки 1 в точку n, 
//который может прыгнуть либо на одну, либо на две точки вперед
int number_of_trajectories(int n)
{
    int K[n+1];
    K[0] = 0;
    K[1] = 1;
    for (int i = 3; i < n; i++) K[i] = K[i-1] + K[i-2];
    return K[n];
}

int main(void)
{
    int finish;
    scanf("%d", &finish);
    printf("the garsshopper has %d trajectories form 1 to %d\n", 
    number_of_trajectories(finish), finish);
    return 0;
}

//не работает, не понимаю почему