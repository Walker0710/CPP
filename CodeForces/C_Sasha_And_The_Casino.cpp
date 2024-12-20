#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int k, x, a;
    cin >> k >> x >> a;

    int aa = a;
    int curr = 1;

    for(int i = 1; i<x; i++) {
        int next = (curr)/(k-1);
        next++;
        curr = curr + next;

        if(curr > a) {
            cout << "NO" << endl;
            return ;
        }
    }

    a = a - curr;

    if(a < 0) {
        cout << "NO" << endl;
        return ;
    }

    a = a*k;

    if(a > aa) {
        cout << "YES" << endl;
        return ; 
    }

    cout << "NO" << endl;
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