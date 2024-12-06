#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int g = __gcd(a, b);
    vector<int> c(n);

    for(int i = 0; i<n; i++) {
        cin >> c[i];
        c[i] = c[i]%g;
    }

    sort(all(c));

    int mini = c[n-1] - c[0];

    for(int i = 0; i<n-1; i++) {
        mini = min(mini, abs(c[i] + g - c[i+1]));
    }

    cout << mini << endl;  
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