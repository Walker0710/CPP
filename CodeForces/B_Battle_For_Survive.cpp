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

    vector<int> a(n);

    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    if(n == 1) {
        cout << a[0] << endl;

        return ;
    }

    if(n == 2) {
        cout << a[1] - a[0] << endl;

        return ;
    }

    int sum = 0;

    for (int i = 0; i<n-2; i++) {
        sum = sum + a[i];
    }

    int yoo = a[n-2] - sum;

    int ans = a[n-1] - yoo;

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