#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n, k;
    cin >> n >> k;

    int sum = 0;

    if (k % 2 == 0)
    {   
        if(k == 4*n - 2) {
            cout << 2*n << endl;
            return ;
        }

        cout << k/2 << endl;
    }

    else
    {
        cout << k/2 + 1 << endl;
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