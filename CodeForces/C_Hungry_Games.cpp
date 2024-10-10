#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

// MLE on TC 4
// void solve()
// {
//     int n, x;
//     cin >> n >> x;

//     vector<int> a(n);

//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//     int ans = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] <= x)
//         {
//             dp[i][i] = a[i];
//             ans++;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (dp[i][j - 1] + a[j] <= x)
//             {
//                 dp[i][j] = dp[i][j - 1] + a[j];
//                 ans++;
//             }
//         }
//     }

//     cout << ans << endl;
// }

// signed main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// 2nd Approch
void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
    cin >> a[i];

    partial_sum(a.begin() + 1, a.end(), a.begin() + 1);
    vector<int> dp(n + 2);

    for (int i = n - 1; i >= 0; --i)
    {
        int q = upper_bound(a.begin(), a.end(), a[i] + x) - a.begin();
        dp[i] = dp[q] + q - i - 1;
    }

    cout << accumulate(dp.begin(), dp.end(), 0ll) << endl;
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
