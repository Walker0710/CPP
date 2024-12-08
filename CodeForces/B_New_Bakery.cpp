#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    if(b > a) {

        int k = b - a;
        k = min(n, k);
        int sum = 0;
        int maxi = max(a, b - n);

        sum = sum + b*(b+1)/2 - maxi*(maxi+1)/2;

        if(n-k > 0)
        sum = sum + (n-k)*a;

        cout << sum << endl;
    }

    else {
        int sum = a*n;
        cout << sum << endl;
    }
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