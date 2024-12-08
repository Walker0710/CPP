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

    int first = a[n-1];
    int second = INT_MIN;

    for(int i = 0; i<n-1; i++) {
        second = max(second, a[i]);
    }


    cout << first + second << endl;
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