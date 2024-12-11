#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    if((p1 + p2 + p3)%2 == 1) {
        cout << -1 << endl;
    }

    else if(p1 + p2 <= p3) {
        cout << p1 + p2 << endl;
    }

    else {
        cout << (p1 + p2 + p3)/2 << endl;
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