#include<iostream>
#include<math.h>

using namespace std;

static int guess;

int getGuess() {

    cout<<"enter the no."<<endl;
    cin>>guess;
}

void evalute(int guess, int randomNo) {

    if(randomNo == guess) {

        cout<<"you guessed the right no."<<endl;
    }

    if(randomNo > guess) {

        cout<<"your guessed no. is smaller"<<endl;
    }

    if(randomNo < guess) {

        cout<<"your guessed no. is bigger"<<endl;
    }
}

int main() {

    int upper;
    cout<<"Enter the upper bound"<<endl;
    cin>>upper;

    int lower;
    cout<<"Enter the lower bound"<<endl;;
    cin>>lower;

    int randomNo = lower + rand()%(upper - lower + 1);

    while(randomNo != guess) {

        getGuess();
        evalute(guess, randomNo);


    }    
}