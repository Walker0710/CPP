#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

void solve()
{
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<int> aEven, aOdd;
    vector<int> bEven, bOdd;

    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            if (i % 2 == 0)
                aEven.push_back(i);
            else
                aOdd.push_back(i);
        }

        if (b[i] == '1') {
            if (i % 2 == 0)
                bEven.push_back(i);
            else
                bOdd.push_back(i);
        }
    }

    if (aEven.size() != bEven.size() || aOdd.size() != bOdd.size()) {
        cout << "NO" << '\n';
    }

    else {
        cout << "YES" << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}