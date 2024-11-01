#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

const int MOD = 1000000007;

// << ,

// int solveRec(int n)
// {
//     if (n == 1 || n == 0)
//     {
//         return 1;
//     }

//     int ans = (solveRec(n - 1) % MOD + (2 * (n - 1) * solveRec(n - 2) % MOD)) % MOD;

//     return ans;
// }




int solveRec(int n, vector<int> &dp) {
    if(n <= 1)
    return 1;

    if(dp[n] != -1)
    return dp[n];

    dp[n] = (solveRec(n-1, dp)%MOD    +   (((n-1)%MOD*solveRec(n-2, dp)%MOD)%MOD*2)%MOD)%MOD;

    return dp[n];
}


void solve()
{
    int n, k;
    cin >> n >> k;

    unordered_set<int> yoo;

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        yoo.insert(a);
        yoo.insert(b);
    }

    int left = n - yoo.size();
    vector<int> dp(n+1, -1);

    int ans = solveRec(left, dp);

    cout << ans << endl;
}




signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

