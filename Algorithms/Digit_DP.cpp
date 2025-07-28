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









class Solution {
public:

int dp[10][2][20][10][10][2];
    string num;
    int k;

    int solve(int pos, bool tight,int modk, int odd, int even, bool Lzero){
        
        if(pos == num.size()){
            return (modk == 0 and (odd == even) and (Lzero == false));
        }
    
        if( dp[pos][tight][modk][odd][even][Lzero] != -1) 
        return dp[pos][tight][modk][odd][even][Lzero];
    
        int limit = tight ? num[pos] -'0' : 9;
        int ans = 0;
        
        for(int i = 0; i <= limit ; i++){
            int newtight = tight && (i==limit);
            bool newLzero = Lzero && (i == 0);
            int newodd = odd + (i%2 == 1);
            int neweven = even + (!newLzero and i%2 == 0);
        
            ans += (solve(pos+1,newtight,(modk*10 + i)%k, newodd, neweven, newLzero));
        }
        
        return dp[pos][tight][modk][odd][even][Lzero] =  ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp,-1,sizeof(dp));
        this->k = k;
    
        num = to_string(low-1);
        auto ans1 = solve(0,true,0,0,0,true);
    
        memset(dp,-1,sizeof(dp));
        num = to_string(high);
    
        auto ans2 = solve(0,true,0,0,0,true);
        return ans2- ans1;
    }
};