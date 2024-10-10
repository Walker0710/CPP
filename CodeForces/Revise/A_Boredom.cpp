#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int n;
    cin >> n;

    int maxi = -1;
    vector<int> a(100005, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
        maxi = max(maxi, x);
    }

    vector<int> dp(100005, 0);
    dp[0] = 0;
    dp[1] = a[1];

    for (int i = 2; i <= 100000; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + (a[i] * i));
    }
    cout << dp[maxi] << endl;
}

signed main()
{
    solve();

    return 0;
}