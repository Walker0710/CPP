#include <bits/stdc++.h>

using namespace std;

// << ,

int dp[1 << 15][15];
vector<int> a;
int n;

int find(int mask, int pre)
{
    if (mask == (1 << n) - 1)
    {
        return abs(pre - a[0]);
    }

    if (dp[mask][pre] != -1)
    return dp[mask][pre];

    int ans = 1e8;
    
    for (int j = 0; j < n; j++)
    {
        if ((mask >> j) & 1)
        continue;
        
        ans = min(ans, abs(pre - a[j]) + find(mask | (1 << j), j));
    }

    return dp[mask][pre] = ans;
}

void buildPath(int mask, int pre, vector<int> &res)
{
    if (mask == (1 << n) - 1)
    return;

    int ans = 1e8, next = -1;

    for (int j = 0; j < n; j++)
    {
        if ((mask >> j) & 1)
        continue;
        
        int nans = abs(pre - a[j]) + find(mask | (1 << j), j);
        
        if (nans < ans)
        {
            ans = nans;
            next = j;
        }
    }

    res.push_back(next);
    
    buildPath(mask | (1 << next), next, res);
}

vector<int> findPermutation(vector<int> &input)
{
    a = input;
    n = a.size();

    memset(dp, -1, sizeof(dp));

    find(1, 0);

    vector<int> res = {0};
    buildPath(1, 0, res);

    return res;
}