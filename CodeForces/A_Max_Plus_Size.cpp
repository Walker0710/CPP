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

    int evenMax = 0;
    int oddMax = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if(i%2 == 1) {
            evenMax = max(a[i], evenMax);
        }

        else {
            oddMax = max(a[i], oddMax);
        }
    }

    // cout << oddMax << " " << evenMax<< endl;

    int ans = 0;

    if(n%2 == 0) {
        ans = n/2 + max(evenMax, oddMax);
    }

    else {

        ans = max(n/2 + 1 + oddMax, n/2 + evenMax);
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