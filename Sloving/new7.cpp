#include<iostream>
#include<time.h>

using namespace std;

enum status {continu, won, lost};

int rollDice() {

    int die1 = 1 + rand()%6;
    int die2 = 1 + rand()%6;

    cout<<"player rolled "<<die1<<" + "<<die2<<" = "<<die1 + die2<<endl;
    return die1 + die2;
}

int main() {

    srand(time(NULL));

    int myPoint = 0;
    enum status gamestatus = continu;
    int sum = rollDice();

    switch(sum) {

        case 7: gamestatus = won;
        break;

        case 11: gamestatus = won;
        break;

        case 2: gamestatus = lost;
        break;

        case 3: gamestatus = lost;
        break;

        case 4: gamestatus = lost;
        break;

        default: gamestatus = continu;
        myPoint = sum;
        cout<<"point is "<<myPoint<<endl;
        break;
    }

    while(gamestatus == continu) {

        sum = rollDice();

        if(sum == myPoint) {

            gamestatus = won;
        }

        else if( sum == 7) {

            gamestatus == lost;
        }
    }

    if(gamestatus == won) {

        cout<<"player wins";
    }

    if(gamestatus == lost) {

        cout<<"player lose";
    }
}

