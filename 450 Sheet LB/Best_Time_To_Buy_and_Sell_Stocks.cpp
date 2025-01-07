#include <bits/stdc++.h>

using namespace std;

// << ,

int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;

    for(int i = 0; i<prices.size(); i++) {
        
        int temp = prices[i] - mini;
        profit = max(temp, profit);

        mini = min(mini, prices[i]);
    }
    return profit;
}