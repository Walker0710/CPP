#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int a, b;
    cin >> a >> b;

    if(a > b) {
        swap(a, b);
    }

    if((a%2 == 1 && a*2 == b) || (a%2 == 1 && b%2 == 1)) {
        cout << "NO" << endl;
    }
    
    else {
        cout << "YES" << endl;
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