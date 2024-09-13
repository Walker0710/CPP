#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <stack>

using namespace std;

int minimumDays(int S, int N, int M) {

    int sunday = S/7;
    int buyingDays = S-sunday;
    int ans = 0;
    int totalFood = S*M;

    if(totalFood%N == 0)
    ans = totalFood/N;

    else 
    ans = totalFood/N + 1;

    if(ans <= buyingDays)
    return ans;

    else 
    return -1;
}