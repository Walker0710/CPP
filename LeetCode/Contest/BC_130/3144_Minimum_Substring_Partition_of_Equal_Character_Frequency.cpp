#include <bits/stdc++.h>

using namespace std;

// << ,

int dp[1001];
int helper(int ind, int n, string &s)
{
    if (ind == n)
    return 0;
    
    if (dp[ind] != -1)
    return dp[ind];
    
    int mini = n;
    unordered_map<char, int> mp;
    
    for (int i = ind; i < n; i++)
    { 
        mp[s[i]]++;
        int prev = -1, flag = 0;
        
        for (auto [x, y] : mp)
        {
            if (prev == -1)
            prev = y;
            
            else
            {
                if (y != prev)
                {
                    flag = 1;
                    break;
                }
            }
        }
        
        if (!flag)
        mini = min(mini, 1 + helper(i + 1, n, s));
    }
 
    return dp[ind] = mini;
}

int minimumSubstringsInPartition(string s)
{
    int n = s.size();
    memset(dp, -1, sizeof(dp));
 
    return helper(0, n, s);
}