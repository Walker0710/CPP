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
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    int ans = 2*(a[n-1] + a[n-2] - a[0] - a[1]);

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