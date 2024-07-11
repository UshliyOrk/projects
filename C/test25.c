#include <stdio.h>
#include <iso646.h>

// ханойские пирамидки рекурсия
// n- номер диска, i- первый столб, k- конечный столб
// 1+2+3 = 6 ==> тертий столб (tmp) = 6-i-k
void hanoi(int n, int i, int k); 

int main(void)
{
    hanoi(8,1,2);

    return 0;
}

void hanoi(int n, int i, int k)
{
    if (n == 1) printf("move disk %d from pin %d to %d\n", n,i,k);
    else
    {
        int tmp = 6-i-k;
        hanoi(n-1, i, tmp);
        printf("move disk %d from pin %d to %d\n", n,i,k);
        hanoi(n-1, tmp, k);
    }
}
