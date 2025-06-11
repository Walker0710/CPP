#include <bits/stdc++.h>

using namespace std;

// << ,

int countPartitions(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n);
    prefix[0] = nums[0];

    for(int i = 1; i<n; i++) {
        prefix[i] = prefix[i-1] + nums[i]; 
    }

    int ans = 0;

    for(int i = 0; i<n-1; i++) {
        int yoo = (prefix[n-1] - 2*prefix[i]);

        if(yoo%2 == 0)
        ans++;
    }

    return ans;
}