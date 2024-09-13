#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    
    int front = 0;
    int prev = values[0];
    int n = values.size();
    int ans = INT_MIN;

    vector<int> dp(n);
    dp[0] = values[0];

    for(int i = 1; i<n; i++) {

        front = values[i] - i;
        ans = max(ans, prev + front);
        prev = max(prev, values[i] + i);
        dp[i] = ans;
    }
    return ans;
}
