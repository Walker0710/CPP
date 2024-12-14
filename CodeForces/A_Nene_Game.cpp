#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int k, q;
    cin >> k >> q;

    vector<int> a(k);
    for(int i = 0; i<k; i++) {
        cin >> a[i];
    }

    for(int i = 0; i<q; i++) {
        int n;
        cin >> n;

        int yoo = 0;

        while (n >= a[0]) // iss condition ko ek baar dekhna 
        {
            yoo = upper_bound(a.begin(), a.end(), n) - a.begin();
            n = n - yoo;
        }
        cout << n << " ";
    }

    cout << endl;
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