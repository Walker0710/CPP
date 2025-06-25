#include <bits/stdc++.h>

using namespace std;

// << ,
long long dp[100005][5];

long long solve(int i, int ind, vector<int> &a, vector<int> &b)
{
    if (ind == 4)
        return 0; 

    if (i == b.size())
        return LLONG_MIN; 

    if (dp[i][ind] != -1)
        return dp[i][ind];

    long long inc = (long long)a[ind] * b[i] + solve(i + 1, ind + 1, a, b);

    long long exc = solve(i + 1, ind, a, b);

    return dp[i][ind] = max(inc, exc);
}

long long maxScore(vector<int> &a, vector<int> &b)
{
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, a, b);
}
