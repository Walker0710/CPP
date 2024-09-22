#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<pair<int, int>> a(n - 1);

//     for (int i = 0; i < n - 1; i++)
//     {
//         int fs;
//         int sc;

//         cin >> fs >> sc;
//         a[i] = {fs, sc};
//     }

//     unordered_set<int> rec;
//     rec.insert(1);
//     int ans = 0;

//     while (rec.size() != n)
//     {
//         ans++;

//         for (int i = 0; i < n - 1; i++)
//         {
//             auto pair = a[i];

//             if (rec.find(pair.first) != rec.end() && rec.find(pair.second) != rec.end())
//             {
//                 continue;
//             }

//             if (rec.find(pair.first) != rec.end() || rec.find(pair.second) != rec.end())
//             {
//                 if (rec.find(pair.first) != rec.end())
//                 {
//                     rec.insert(pair.second);
//                 }

//                 else
//                 {
//                     rec.insert(pair.first);
//                 }
//             }
//         }
//     }

//     cout << ans << endl;
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

// 2nd approh

// << ,

void dfs(int node, int prev, int &mx, int res, int cur, map<pair<int, int>, int> &mpp, vector<int> adj[])
{
    mx = max(mx, res);
    for (auto it : adj[node])
    {
        if (it != prev)
        {
            int i = mpp[{it, node}];
            dfs(it, node, mx, res + (i < cur), i, mpp, adj);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    map<pair<int, int>, int> mpp;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mpp[{u, v}] = i + 1;
        mpp[{v, u}] = i + 1;
    }

    int mx = 0;
    dfs(0, -1, mx, 0, n, mpp, adj);
    cout << mx << endl;
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
