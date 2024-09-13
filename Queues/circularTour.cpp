#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>

using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

//1st approch

int tour(petrolPump p[],int n) {

    int carry = 0;
    int deci;

    for(int i = 0; i<n; i++) {

        for(int j = i; j<n;) {

            //minus wli chiz
            if(deci < 0) {

                break;
            }

            else {

                j++;
            }
        }
    }
}

//2nd approch
int tour(petrolPump p[],int n) {

    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int i = 0; i<n; i++) {

        balance = p[i].petrol - p[i].distance + balance;

        if(balance < 0) {

            deficit = deficit + balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >= 0) {

        return start;
    }

    else {

        return -1;
    }
}

