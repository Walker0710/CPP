#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> yoo(26, 0);

    for(int i = 0; i<n; i++) {
        string to;
        cin >> to;

        yoo[to[0] - 'a'] = 1;
    }

    bool check = true;

    for(int i = 0; i<m; i++) {
        string to;
        cin >> to;

        for(auto ch : to) {
            if(yoo[ch - 'A'] == 0) {
                check = false;
            }
        }
    }

    if(check) {
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