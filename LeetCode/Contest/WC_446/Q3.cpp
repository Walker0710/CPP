#include <bits/stdc++.h>

using namespace std;

// << ,

vector<long long> resultArray(vector<int> &nums, int k)
{
    int n = nums.size();
    long long total = 1;
    vector<long long> prefix(n);
    vector<long long> suffix(n);

    prefix[0] = nums[0];
    suffix[n - 1] = nums[n - 1];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * nums[i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        total = total * nums[i];
    }

    vector<long long> ans(k, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            long long yoo = total / (prefix[i] * suffix[j]);

            ans[yoo % k]++;
        }
    }

    return ans;
}

vector<long long> resultArray(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<long long> ans(k, 0);

    for (int i = 0; i < n; i++)
    {
        long long prod = 1;

        for (int j = i; j < n && j - i < 20; j++)
        {
            prod = (prod * nums[j]) % k;
            ans[prod]++;

            if (prod == 0)
                break;
        }
    }

    return ans;
}

vector<long long> resultArray(vector<int> &nums, int k)
{
    lli n = nums.size();
    vector<vector<lli>> dp(n + 1, vector<lli>(k, 0));
    vector<lli> ans(k, 0);
    int t = nums[0] % k;
    dp[0][t]++;
    ans[t]++;

    for (int i = 1; i < n; i++)
    {
        int t = nums[i] % k;

        for (int j = 0; j < k; j++)
        {
            if (dp[i - 1][j] > 0)
            {
                dp[i][(j * t) % k] += dp[i - 1][j];
            }
        }

        dp[i][t]++;

        for (int j = 0; j < k; j++)
        {
            ans[j] += dp[i][j];
        }
    }

    return ans;
}