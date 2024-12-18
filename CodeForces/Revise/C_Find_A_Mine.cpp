#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,
int query(int x, int y) {
    cout << "? " << x << " " << y << endl;

    int res;
    cin >> res;
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int res = query(1, 1);

    int res2 = 0, res3 = 0;
    int x2 = 0, y2 = 0, y3 = 0, x3 = 0;

    if(res <= n-1) {
        x2 = res+1;
        y2 = 1;
        res2 = query(res+1, 1);
    }

    else {
        x2 = n;
        y2 = res - n + 2;
        res2 = query(n, res - n + 2);
    }

    if(res <= m-1) {
        x3 = 1;
        y3 = res + 1;
        res3 = query(1, res + 1);
    }

    else {
        x3 = res - m + 2;
        y3 = m;
        res3 = query(res - m + 2, m);
    }

    x3 = x3 + (res3/2);
    y3 = y3 - (res3/2);
    x2 = x2 - (res2/2);
    y2 = y2 + (res2/2);

    int res4 = query(x3, y3);

    if(res4 == 0) {
        cout << "! " << x3 << " "<< y3 << endl; 
    } 

    else {
        cout << "! " << x2 << " " << y2 << endl;
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