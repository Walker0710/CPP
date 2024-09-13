#include <stdio.h>

int a = 1;
int b = 2;
int c = 3;
void towerofhanoi(int number)
{
    if (number == 3)
    {
        printf("%d->%d\n", a, c);
        printf("%d->%d\n", a, b);
        printf("%d->%d\n", c, b);
        printf("%d->%d\n", a, c);
        printf("%d->%d\n", b, a);
        printf("%d->%d\n", b, c);
        printf("%d->%d\n", a, c);
    }
    else if (number % 2 == 0)
    {
        towerofhanoi(number - 1);
        printf("1->2\n");
        a = 3;
        b = 1;
        c = 2;
        towerofhanoi(number - 1);
    }
    else if (number % 2 == 1)
    {
        towerofhanoi(number - 1);
        printf("1->3\n");
        a = 2;
        b = 3;
        c = 1;
        towerofhanoi(number-1);
    }
}
int main()
{
    int number;
    scanf("%d", &number);
    towerofhanoi(number);
    return 0;
}