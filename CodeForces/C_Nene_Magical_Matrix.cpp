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

    int sum = 0;
    
    for(int i = 1; i<=n; i++) {
        sum += i*(2*i - 1);
    }

    cout << sum << " " << 2*n << endl;

    for(int i = n-1; i>=0; i--) {
        for(int type = 1; type <= 2; type++) {
            cout << type << " " << i+1;

            for(int j = 1; j <= n; j++) {
                cout << " " << j;
            }
            cout << endl;
        }
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