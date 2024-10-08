#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> aa(k), bb(k);
    unordered_map<int, int> boys, girls;

    for(int i = 0; i<k; i++) {
        cin >> aa[i];
        boys[aa[i]]++;
    }

    for(int i = 0; i<k; i++) {
        cin >> bb[i];
        girls[bb[i]]++;
    }

    int ans = 0;

    for(int i = 0; i<k; i++) {
        ans = ans + (k - boys[aa[i]] - girls[bb[i]] + 1);
    }

    cout << ans/2 << endl;
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