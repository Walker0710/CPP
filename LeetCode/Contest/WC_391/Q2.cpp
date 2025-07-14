#include <bits/stdc++.h>

using namespace std;

// << ,

int maxBottlesDrunk(int numBottles, int numExchange)
{
    long long sum  = 0;
    long long bottles = numBottles;
    long long exchange = numExchange;

    while (bottles >= exchange)
    {
        sum += bottles - exchange;
        bottles = bottles - exchange;
        exchange++;
        bottles++;
    }

    sum += bottles; 

    return sum;
}




int maxBottlesDrunk(int numBottles, int numExchange) {
    int total = numBottles;
    int empty = numBottles;

    while (empty >= numExchange) {

        empty -= numExchange;
        total += 1;
        empty += 1;      
        numExchange += 1;
    }

    return total;
}
