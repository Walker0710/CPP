#include <bits/stdc++.h>

using namespace std;

// << ,

long long maximumHappinessSum(vector<int> &happiness, int k)
{
    int n = happiness.size();
    sort(happiness.rbegin(), happiness.rend());

    long long ans = 0;

    for(int i = 0; i<n && i < k; i++) {
        if(happiness[i] - i > 0) {
            ans = ans + happiness[i] - i;
        } 
    }

    return ans;
}