#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int MOD = 1e9 + 7;

    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
    cin >> a[i];

    int min1 = *min_element(a.begin(), a.end());
    int cnt = 0;

    for (int x : a)
    {
        if (min1 == x)
            cnt++;

        if ((min1 & x) != min1)
        {
            cout << 0 << endl;
            return;
        }
    }

    int fact = 1;

    for (int i = 1; i <= n - 2; i++)
        fact = (fact * i) % MOD;

    int ans = (cnt * (cnt - 1)) % MOD;

    ans = (ans * fact) % MOD;
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