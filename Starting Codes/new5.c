#include<stdio.h>
#include<stdlib.h>

int main() {

    printf("%s", "Enter seed : ");
    int seed;
    scanf("%d", &seed);

    srand(seed);

    for(int i = 1; i <= 10; ++i) {

        printf("%d ", 1 + (rand() % 6));
    }
    
}
