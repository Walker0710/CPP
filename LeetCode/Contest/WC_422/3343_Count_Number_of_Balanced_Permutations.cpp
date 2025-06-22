#include <bits/stdc++.h>

using namespace std;

// << ,

const int MOD = 1e9 + 7;

int expo(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1)
            res = (1ll * res * a) % MOD;
        b >>= 1;
        a = (1ll * a * a) % MOD;
    }
    return res;
}

int countBalancedPermutations(string num)
{
    vector<int> fr(10), fact(num.size() + 1, 1), ifact(num.size() + 1, 1);
    int sum = 0;

    for (auto &i : num)
        fr[i - '0']++, sum += (i - '0');

    if ((sum % 2 == 1))
        return 0;

    for (int i = 1; i <= num.size(); i++)
    {
        fact[i] = (1ll * i * fact[i - 1]) % MOD;
        ifact[i] = expo(fact[i], MOD - 2);
    }

    vector<vector<vector<int>>> dp(10, vector<vector<int>>(num.size() / 2 + 1, vector<int>(sum + 1, -1)));

    int permutationsCount = (1ll * fact[num.size() / 2] * fact[(num.size() + 1) / 2]) % MOD;

    auto f = [&](int number, int taken, int currentSum, auto &&self) -> int
    {
        if (number == 10)
        {
            return (currentSum == sum / 2 && taken == num.size() / 2 ? permutationsCount : 0);
        }

        if (dp[number][taken][currentSum] != -1)
            return dp[number][taken][currentSum];

        int ways = 0;

        for (int i = 0; i <= min(fr[number], (int)num.size() / 2 - taken); i++)
        {
            ways = (ways + (1ll * (1ll * ifact[i] * ifact[fr[number] - i]) % MOD * self(number + 1, taken + i, currentSum + i * number, self)) % MOD) % MOD;
        }

        return dp[number][taken][currentSum] = ways;
    };

    return f(0, 0, 0, f);
}