#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        
        if (x > y)
        swap(x, y);
        
        v[y] = max(v[y], x);
    }

    int maxoPos = 0;
    long long ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        maxoPos = max(maxoPos, v[i]);
        ans += i - maxoPos;
    }
    cout << ans << '\n';
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