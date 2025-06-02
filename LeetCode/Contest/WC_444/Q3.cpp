#include <bits/stdc++.h>

using namespace std;

// << ,

unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> dp;

long long solve(int index, int sum, int isOdd, long long product, vector<int> &nums, int k, int limit)
{
    if (index == nums.size())
    {
        if (sum == k && isOdd != 0 && product <= limit)
            return product;
        else
            return -1;
    }

    if (dp.count(index) && dp[index].count(sum) && dp[index][sum].count(product) && dp[index][sum][product].count(isOdd))
    {
        return dp[index][sum][product][isOdd];
    }

    long long ans = solve(index + 1, sum, isOdd, product, nums, k, limit);

    long long newProduct = product * nums[index];

    if (isOdd == 0)
    {
        ans = max(ans, solve(index + 1, sum + nums[index], 1, newProduct, nums, k, limit));
    }

    else if (isOdd == 1)
    {
        ans = max(ans, solve(index + 1, sum - nums[index], 2, newProduct, nums, k, limit));
    }

    else if (isOdd == 2)
    {
        ans = max(ans, solve(index + 1, sum + nums[index], 1, newProduct, nums, k, limit));
    }

    return dp[index][sum][product][isOdd] = ans;
}

int maxProduct(vector<int> &nums, int k, int limit)
{
    dp.clear();
    long long res = solve(0, 0, 0, 1, nums, k, limit);
    return res == -1 ? -1 : (int)res;
}