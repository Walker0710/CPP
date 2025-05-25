#include <bits/stdc++.h>

using namespace std;

// << ,

// O(nlogn)
vector<int> countBits(int n)
{
    vector<int> res(n + 1);
    for (int num = 1; num <= n; num++)
    {
        for (int i = 0; i < 32; i++)
        {
            if (num & (1 << i))
            {
                res[num]++;
            }
        }
    }
    return res;
}


// O(n)
vector<int> countBits(int n)
{
    vector<int> dp(n + 1);
 
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i >> 1] + (i & 1);
    }
 
    return dp;
}