#include <bits/stdc++.h>

using namespace std;

// << ,


// https://www.youtube.com/watch?v=cthI6e5KGgg

vector<int> cnt;
int k;
const int mod = 1e9 + 7;
int dp[801][2][801];

int solve(const string &s, int i, bool tight, int setBits)
{
    if (i == s.size())
        return (tight || setBits == 0) ? 0 : cnt[setBits] < k;
    
    if (dp[i][tight][setBits] != -1)
        return dp[i][tight][setBits];

    if (tight)
    {
        if (s[i] == '0')
            return solve(s, i + 1, true, setBits);

        int res = solve(s, i + 1, true, setBits + 1);
        res = (res + solve(s, i + 1, false, setBits)) % mod;

        return dp[i][tight][setBits] = res;
    }

    int res = solve(s, i + 1, false, setBits + 1);
    res = (res + solve(s, i + 1, false, setBits)) % mod;

    return dp[i][tight][setBits] = res;
}

int countKReducibleNumbers(std::string s, int k)
{
    this->k = k;
    this->cnt = std::vector<int>(801, 0);
    memset(dp, -1, sizeof(dp));

    for (int i = 2; i <= 800; i++)
    {
        int setBits = __builtin_popcount(i);
        cnt[i] = 1 + cnt[setBits];
    }
    
    return solve(s, 0, true, 0);
}



#define ll long long

ll countValidNumbers(int idx, int tight, string &numStr, string &suffix, int limit, int numLength, vector<vector<ll>> &dp)
{
    if (idx == numLength)
        return 1;

    if (dp[idx][tight] != -1)
        return dp[idx][tight];

    ll lowerBound = 0, count = 0;

    int upperBound = tight ? min(limit, numStr[idx] - '0') : limit;

    int suffixStartIdx = numLength - suffix.size();

    if (suffixStartIdx <= idx)
    {
        lowerBound = suffix[idx - suffixStartIdx] - '0';
        upperBound = min(upperBound, suffix[idx - suffixStartIdx] - '0');
    }

    for (int i = lowerBound; i <= upperBound; i++)
        count += countValidNumbers(idx + 1, tight && (i == numStr[idx] - '0'), numStr, suffix, limit, numLength, dp);

    return dp[idx][tight] = count;
}

ll numberOfPowerfulInt(ll start, ll finish, int limit, string s)
{
    string upperLimit = to_string(finish);
    string lowerLimit = to_string(start - 1);

    int upperLength = upperLimit.size();
    int lowerLength = lowerLimit.size();

    ll upperCount = 0;
    ll lowerCount = 0;
    
    vector<vector<ll>> dp(17, vector<ll>(2, -1));

    if (s.size() <= upperLength)
        upperCount = countValidNumbers(0, 1, upperLimit, s, limit, upperLength, dp);

    dp.assign(17, vector<ll>(2, -1));

    if (s.size() <= lowerLength)
        lowerCount = countValidNumbers(0, 1, lowerLimit, s, limit, lowerLength, dp);

    return upperCount - lowerCount;
}