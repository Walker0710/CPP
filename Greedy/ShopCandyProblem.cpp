#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <stack>

using namespace std;

vector<int> candyStore(int candies[], int N, int K) {

    sort(candies, candies+N);

    int mini = 0;
    int buy = 0; 
    int free = N-1;

    while(buy <= free) {

        mini = mini + candies[buy];
        buy++;
        free = free - K;
    }

    int maxi = 0;
    buy = N-1; 
    free = 0;

    while(buy >= free) {

        maxi = maxi + candies[buy];
        buy--;
        free = free + K;
    }

    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);
    return ans;
}