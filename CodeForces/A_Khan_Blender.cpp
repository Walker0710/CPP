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

    int x, y;
    cin >> x >> y;

    int mini = min(x, y);

    if(n%mini == 0) {
        cout << n/mini << endl;
    }

    else {
        cout << n/mini + 1 << endl;
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