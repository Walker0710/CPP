#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n;
    int m;

    cin >> n >> m;

    // if(n == 1 || m == 1)
    // {
    //     cout << "NO";
    // }

     if (n >= 2 && m > 2) {
        cout << "YES" << endl;
    } 

    else if (m >= 2 && n > 2) {
        cout << "YES" << endl;
    }  

    else {
        cout << "NO" << endl;
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