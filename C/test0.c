#include <stdio.h>
#include <time.h>

void greet(char name[20])
{
    printf("Hello, %s, nice to meet you!\n", name);
}

int get_year(int age)
{
    time_t mytime = time(NULL);
    struct tm *now = localtime(&mytime);
    return now->tm_year+1900-age;
}

int main(void)
{
    char name[20];
    int age;
    printf("input your name age -->  ");
    scanf("%s %d", name, &age);
    greet(name);
    printf("you was born in %d", get_year(age));
    return 0;
}