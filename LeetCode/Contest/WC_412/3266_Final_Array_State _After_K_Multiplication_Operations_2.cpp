#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    using pll = pair<long long, int>;
    const int MOD = 1e9 + 7;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
    }

    for (int i = 0; i < k; i++)
    {
        auto [val, idx] = pq.top();
        pq.pop();

        pq.push({val * 1LL * multiplier, idx});
    }

    vector<int> result(nums);

    while (!pq.empty())
    {
        auto [val, idx] = pq.top();
        pq.pop();

        result[idx] = val % MOD;
    }

    return result;
}

long long mod_pow(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    using pll = pair<long long, int>;
    const int MOD = 1e9 + 7;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
    }

    if (nums.size() == 1)
    {
        long long power = mod_pow(multiplier, k, MOD);
        nums[0] = (1LL * nums[0] * power) % MOD;
        return nums;
    }

    for (int i = 0; i < k; i++)
    {
        auto [val, idx] = pq.top();
        pq.pop();

        __int128 prod = (__int128)val * multiplier;
        pq.push({(long long)(prod), idx});
    }

    vector<int> result(nums);

    while (!pq.empty())
    {
        auto [val, idx] = pq.top();
        pq.pop();

        result[idx] = val % MOD;
    }

    return result;
}
















const long long mod = 1000000007;

long long power_mod(long long base, long long exp, long long mod)
{
    long long result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp = exp / 2;
    }

    return result;
}

vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    if (multiplier == 1)
        return nums; // do not miss this!!

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    int n = nums.size();

    for (int i = 0; i < n; i++)
        pq.push({nums[i], i});

    unordered_map<int, int> m, m1;
    // m for storing number of operations at each index
    // m1 to know if all elements have got an operation
    while (1)
    {
        if ((int)m1.size() == n || k == 0)
            break; // no more operations or state achieved

        long long x = pq.top().first, y = pq.top().second;

        pq.pop();
        x *= multiplier;
        pq.push({x, y});
        m1[y]++;
        k--;
    }

    vector<long long> v(n); // to avoid integer overflow
    // This vector will store the elements after ideal state is achieved
    while (!pq.empty())
    {
        long long x = pq.top().first, y = pq.top().second;
        v[y] = x;
        pq.pop();
    }

    int rep = k / n, md = k % n;

    for (int i = 0; i < n; i++)
        pq.push({v[i], i});
    // I had to push it again because I did not declare v initially due to contest pressure. Better to do that.
    while (!pq.empty())
    {
        int x = pq.top().second;
        m[x] = rep;

        if (md > 0)
            m[x]++, md--;
        // index x has been assigned its number of operations
        pq.pop();
    }
    // Now just compute every value while calling power_mod funtion
    for (int i = 0; i < n; i++)
    {
        long long mlt = power_mod(multiplier, m[i], mod);
        v[i] = ((v[i] % mod) * (mlt % mod)) % mod;
        nums[i] = v[i];
    }
    return nums;
}