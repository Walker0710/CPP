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

    // Store positions of 1s according to their parity
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

    // Number of 1s in each parity group must be the same
    if (aEven.size() != bEven.size() ||
        aOdd.size() != bOdd.size()) {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;

    // Match kth even-positioned 1 in a with kth even-positioned 1 in b
    for (int i = 0; i < aEven.size(); i++) {
        ans += abs(aEven[i] - bEven[i]) / 2;
    }

    // Match kth odd-positioned 1 in a with kth odd-positioned 1 in b
    for (int i = 0; i < aOdd.size(); i++) {
        ans += abs(aOdd[i] - bOdd[i]) / 2;
    }

    cout << ans << '\n';
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