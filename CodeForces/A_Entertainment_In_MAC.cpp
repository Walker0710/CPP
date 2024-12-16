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

    string s;
    cin >> s;

    string revv = s;
    reverse(all(revv));

    if(s > revv) {
        cout << revv << s << endl;
    }

    else {
        cout << s << endl;
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