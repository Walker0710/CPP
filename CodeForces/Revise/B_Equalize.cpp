#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(all(a));
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int yoo = 0;
    int ans = 0;
    
    for (int i = 0; i < a.size(); i++)
    {
        while (a[i] - a[yoo] >= n)
        {
            yoo++;
        }
        ans = max(ans, i - yoo + 1);
    }

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