#include <bits/stdc++.h>

using namespace std;

// << ,

long long findMaximumScore(vector<int> &nums)
{
    int n = nums.size();
    long long ans = 0;

    int i = 0;

    while (i < nums.size() - 1)
    {
        int j = i+1;

        while (j < n && nums[i] > nums[j])
        {
            j++;
        }

        if(j == n) {
            ans = ans + 1LL*(j - i - 1)*nums[i];
            return ans;
        }

        else {
            ans = ans + 1LL*(j-i)*nums[i];
        }

        i = j;
    }

    return ans;    
}