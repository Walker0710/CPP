#include <bits/stdc++.h>

using namespace std;

// << ,

long long maximumTotalSum(vector<int> &maximumHeight)
{
    int n = maximumHeight.size();
    sort(maximumHeight.begin(), maximumHeight.end());

    for(int i = n-2; i>=0; i--) {
        maximumHeight[i] = min(maximumHeight[i], maximumHeight[i+1] - 1);

        if(maximumHeight[i] <= 0)
        return -1;
    }

    long long ans = 0;

    for(auto yoo : maximumHeight) {
        ans = ans + yoo;
    }

    return ans;
}