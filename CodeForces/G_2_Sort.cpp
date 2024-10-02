#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    cin >> a[i];

    int cnt = 1;
    int ans = 0;

    for (int i = 1; i<n; i++) {
        if(a[i-1] < 2*a[i]) {
            cnt++;
        }

        else {
            cnt = 1;
        }

        if(cnt > k) 
        ans++;
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