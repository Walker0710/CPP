#include <bits/stdc++.h>

using namespace std;

// << ,

const int MOD = 1e9 + 7;

int dp[201][201][2][201];

int solve(int zero, int one, int last, int streak, int limit)
{

    if (zero == 0 && one == 0)
        return 1;

    if (dp[zero][one][last][streak] != -1)
        return dp[zero][one][last][streak];

    int ans = 0;

    if (zero > 0)
    {
        if (last != 0 || streak < limit)
            ans = (ans + solve(zero - 1, one, 0, (last == 0 ? streak + 1 : 1), limit)) % MOD;
    }

    if (one > 0)
    {
        if (last != 1 || streak < limit)
            ans = (ans + solve(zero, one - 1, 1, (last == 1 ? streak + 1 : 1), limit)) % MOD;
    }

    return dp[zero][one][last][streak] = ans;
}

int numberOfStableArrays(int zero, int one, int limit)
{
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    if (zero > 0)
        ans = (ans + solve(zero - 1, one, 0, 1, limit)) % MOD;
    if (one > 0)
        ans = (ans + solve(zero, one - 1, 1, 1, limit)) % MOD;
    return ans;
}




int MOD = 1e9 + 7;
int dp[201][201][2];

int solveRE(int one, int zero, bool flag, int limit)
{
    if (one == 0 && zero == 0)
    return 1;

    int ans = 0;

    if (flag)
    { 
        for (int i = 1; i <= min(one, limit); i++)
        {
            ans = (ans + solveRE(one - i, zero, false, limit)) % MOD;
        }
    }

    else
    { 
        for (int i = 1; i <= min(zero, limit); i++)
        {
            ans = (ans + solveRE(one, zero - i, true, limit)) % MOD;
        }
    }

    return ans;
}

int solveME(int one, int zero, bool flag, int limit)
{
    if (one == 0 && zero == 0)
    return 1;

    if (dp[one][zero][flag] != -1)
    {
        return dp[one][zero][flag];
    }

    int ans = 0;

    if (flag)
    {
        for (int i = 1; i <= min(one, limit); i++)
        {
            ans = (ans + solveME(one - i, zero, false, limit)) % MOD;
        }
    }

    else
    {
        for (int i = 1; i <= min(zero, limit); i++)
        {
            ans = (ans + solveME(one, zero - i, true, limit)) % MOD;
        }
    }

    return dp[one][zero][flag] = ans;
}

int numberOfStableArrays(int zero, int one, int limit)
{
    memset(dp, -1, sizeof(dp));

    int startWithOne = solveME(one, zero, true, limit);   
    int startWithZero = solveME(one, zero, false, limit); 

    return (startWithOne + startWithZero) % MOD;
}