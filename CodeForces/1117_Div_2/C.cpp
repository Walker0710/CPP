#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<int> parent(n + 1);

    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
    }

    int m;
    cin >> m;

    vector<int> dam(m);

    for (int i = 0; i < m; i++)
    {
        cin >> dam[i];
    }

    int skip = *min_element(all(dam));

    cout << m - 1 << "\n";

    for (int u : dam)
    {
        if (u != skip)
        {
            cout << u << " ";
        }
    }

    cout << "\n";
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