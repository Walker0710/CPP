#include <bits/stdc++.h>

using namespace std;

// << ,

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int buy = prices[0];

    int ans = 0;

    for(int i = 1; i<n; i++) {
        ans = max(ans, prices[i] - buy);
        buy = min(prices[i], buy);
    }

    return ans;
}