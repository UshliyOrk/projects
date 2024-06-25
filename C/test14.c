#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>



int lengthOfNumber(int n)
{
    int res = 0;
    while (n)
    {
        n/=10;
        res+=1;
    }
    
    return res;
}

int sumOfDigits(int n)
{
    int res = 0;
    while (n)
    {
        res += n%10;
        n/=10;
    }
    
    return res;
}

int productOfDigits(int n)
{
    int res = 1;
    while (n)
    {
        res *= n%10;
        n/=10;
    }
    
    return res;
}

bool anyIsOdd(int n)
{
    //bool res = false; // false == 0
    while (n)
    {
        int digit = n%10;
        /*
        res = res or (digit%2==0);
        в этом случае все работает как сумма, но это не эффективно т.к
        перербираются все числа
        */
       if (digit % 2 == 0) return true; //выход из цикла, если находится истина
       n/=10;
    }
    
    return false;
}

bool allIsOdd(int n)
{
    bool res = true; // true == 1
    while (n)
    {
        int digit = n%10;
        /*
        res = res and (digit%2==0);
        работает как умножение, так же не эффективно
        */
       if (digit % 2 != 0) return false; //выход из цикла, если находится ложь
       n/=10;
    }
    
    return true;
}

int main(void)
{
    int x;
    printf("enter your number --> ");
    scanf("%d", &x);
    printf("length: %d\n", lengthOfNumber(x));
    printf("sum: %d\n", sumOfDigits(x));
    printf("product: %d\n", productOfDigits(x));
    printf("any is odd: %s\n", anyIsOdd(x)? "true":"false");
    printf("all is odd: %s\n", allIsOdd(x)? "true":"false");
    
    return 0;
}