#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,
void dfs(int node, vector<bool> &visi, unordered_map<int, list<int>> &g, int cnt, vector<int> &color)
{
    visi[node] = true;
    color[node] = cnt;

    for (auto i : g[node])
    {
        if (!visi[i])
        {
            dfs(i, visi, g, cnt, color);
        }
    }
}

void dfs2(int node, vector<bool> &visi2, unordered_map<int, list<int>> &f2)
{
    visi2[node] = true;

    for (auto i : f2[node])
    {
        if (!visi2[i])
        {
            dfs2(i, visi2, f2);
        }
    }
}

void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    unordered_map<int, list<int>> f;

    for (int i = 0; i < m1; i++)
    {
        int u, v;
        cin >> u >> v;

        f[u - 1].push_back(v - 1);
        f[v - 1].push_back(u - 1);
    }

    unordered_map<int, list<int>> g;

    for (int i = 0; i < m2; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    vector<int> color(n);
    vector<bool> visi(n, false);
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {

        if (!visi[i])
        {

            dfs(i, visi, g, cnt, color);
            cnt++;
        }
    }

    int yoo = 0;
    unordered_map<int, list<int>> f2;

    for (auto i : f)
    {
        int color1 = color[i.first];

        for (auto neig : i.second)
        {
            if (color[neig] != color1)
            {
                yoo++;
            }

            else {
                f2[i.first].push_back(neig);
                f2[neig].push_back(i.first);
            }
        }
    }

    vector<bool> visi2(n);
    int cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visi2[i])
        {
            dfs2(i, visi2, f2);
            cnt2++;
        }
    }

    int ans = yoo + abs(cnt2 - cnt);
    cout << (ans+1)/2 << endl;
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
