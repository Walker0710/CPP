#include<stdio.h>

int main() {

    int n=5;
     int *const a=&n;
    int b=5;
    a=&b;
    n++;
    printf("%d\n%d",*(a+1),n);

}