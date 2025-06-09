#include <bits/stdc++.h>

using namespace std;

// << ,

void dfs(int index, vector<int> &nums, int k, int first, int last, long long &result, const int MOD)
{
    if (index == nums.size())
    {
        if (k >= 0 && first != -1)
        {
            result = (result + nums[first] + nums[last]) % MOD;
        }
        return;
    }

    if (first == -1)
    {
        // inc
        dfs(index + 1, nums, k - 1, index, index, result, MOD);

        // exc
        dfs(index + 1, nums, k, first, last, result, MOD);
    }

    else
    {
        // inc
        dfs(index + 1, nums, k - 1, first, index, result, MOD);

        // exc
        dfs(index + 1, nums, k, first, last, result, MOD);
    }
}

int minMaxSums(vector<int> &nums, int k)
{
    const int MOD = 1e9 + 7;
    long long result = 0;

    sort(nums.begin(), nums.end());

    dfs(0, nums, k, -1, -1, result, MOD);

    return result % MOD;
}

int minMaxSums(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int ans = 0;
    int MOD = 1e9 + 7;
    vector<vector<int>> ncr(nums.size() + 1, vector<int>(k + 1, 0));

    ncr[0][0] = 1;
 
    for (int n = 1; n <= nums.size(); n++)
    {
        ncr[n][0] = 1;
 
        for (int r = 1; r <= k; r++)
            ncr[n][r] = (ncr[n - 1][r - 1] + ncr[n - 1][r]) % MOD;
    }

    for (int n = 0; n < nums.size(); n++)
    {
        int numberOfSubsequences = 0;
 
        for (int r = 0; r <= k - 1; r++)
            if (n >= r)
                numberOfSubsequences = (numberOfSubsequences + ncr[n][r]) % MOD;
 
        ans = (ans + (long long)(nums[n] + nums[nums.size() - n - 1]) * numberOfSubsequences) % MOD;
    }
    return ans;
}










// chat gpt
const int MOD = 1e9 + 7;
const int MAXN = 100005;

long long fact[MAXN], invfact[MAXN];

long long modpow(long long a, long long b) {
    long long res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i-1] * i % MOD;
        invfact[i] = modpow(fact[i], MOD-2);
    }
}

long long C(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int minMaxSums(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    precompute();
    
    long long result = 0;
    
    for(int i = 0; i < n; ++i) {
        long long max_contrib = 0, min_contrib = 0;
        
        // max_contrib → nums[i] is last element (max)
        for(int sz = 1; sz <= k; ++sz) {
            long long ways = C(i, sz-1);
            max_contrib = (max_contrib + ways) % MOD;
        }
        max_contrib = max_contrib * nums[i] % MOD;
        
        // min_contrib → nums[i] is first element (min)
        for(int sz = 1; sz <= k; ++sz) {
            long long ways = C(n-i-1, sz-1);
            min_contrib = (min_contrib + ways) % MOD;
        }
        min_contrib = min_contrib * nums[i] % MOD;
        
        result = (result + max_contrib - min_contrib + MOD) % MOD;
    }
    
    return result;
}
