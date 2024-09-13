#include<stdio.h>

int main() {

    float side = 0.0;

    int i = 0;

    float peri = 0.0;

    while(i>0)  {

        printf("enter the value of side and enter 0 to stop");
        scanf("%f",side);

        if(side == 0) {

            print("thank you \n");
            break;
        }

        i++;
        peri = peri + side;

    }

    int i;

    switch(i) {

        case 3: printf("Trinagle");
        break;

        case 4: printf("quadri");
        break;

        case 5: printf("pentagon");
        break;
        
        case 6: printf("hexagon");
        break;

        case 7: printf("Heptagon");
        break;

        case 8: printf("octagon");
        break;

        case 9: printf("nonane");
        break;

        case 10: printf("decane");
        break;


    }
}