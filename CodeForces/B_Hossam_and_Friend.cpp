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
    int m;

    cin >> n >> m;
    vector<pair<int, int>> notFrnd;

    for (int i = 0; i < m; i++)
    {
        int x;
        int y;

        cin >> x >> y;
        notFrnd.push_back(make_pair(min(x, y), max(x, y)));
    }

    notFrnd.push_back(make_pair(n + 1, n + 1));
    sort(all(notFrnd));

    multiset<int> ms;

    for (auto it : notFrnd)
    {
        ms.insert(it.second);
    }

    int ans = 0;
    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = ans + *ms.begin() - i;

        while (j < m && notFrnd[j].first == i)
        {
            ms.erase(ms.find(notFrnd[j].second));
            j++;
        }
    }

    cout << ans << endl;
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

// << ,

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v(n + 1, 0);
//     for (int i = 0; i < m; ++i)
//     {
//         int x, y;
//         cin >> x >> y;
        
//         if (x > y)
//         swap(x, y);
        
//         v[y] = max(v[y], x);
//     }
//     int maxoPos = 0;
//     long long ans = 0;
//     for (int i = 1; i <= n; ++i)
//     {
//         maxoPos = max(maxoPos, v[i]);
//         ans += i - maxoPos;
//     }
//     cout << ans << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }