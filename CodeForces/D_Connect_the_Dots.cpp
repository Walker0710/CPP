#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

//TLE on 7
// void makeSet(vector<int> &parent, vector<int> &rank, int n)
// {

//     for (int i = 0; i < n; i++)
//     {
//         parent[i] = i;
//         rank[i] = 0;
//     }
// }

// int findParent(vector<int> &parent, int node)
// {
//     if (parent[node] == node)
//         return node;

//     return findParent(parent, parent[node]);
// }

// // path compression
// int findParent1(vector<int> &parent, int node)
// {

//     if (parent[node] == node)
//         return node;

//     return parent[node] = findParent(parent, parent[node]);
// }

// void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
// {
//     u = findParent1(parent, u);
//     v = findParent1(parent, v);

//     if (rank[u] < rank[v])
//         parent[u] = v;

//     else if (rank[v] < rank[u])
//         parent[v] = u;

//     else
//     {
//         parent[v] = u;
//         rank[u]++;
//     }
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> parent(n + 1);
//     vector<int> rank(n + 1);

//     makeSet(parent, rank, n + 1);

//     while (m--)
//     {
//         int a, d, k;
//         cin >> a >> d >> k;

//         for (int i = 1; i <= k; i++)
//         {
//             if (a + d * i <= n)
//             {
//                 unionSet(a, a + d * i, parent, rank);
//             }
//         }
//     }

//     set<int> yoo;

//     for (int i = 1; i < n + 1; i++)
//     {
//         yoo.insert(findParent1(parent, i));
//     }

//     int ans = yoo.size();
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


// 2nd approch 
 
int find(int x, vector<int> &par)
{
    if (par[x] != x)
    {
        return par[x] = find(par[x], par);
    }
    else
    {
        return x;
    }
}
 
void uni(int x, int y, vector<int> &sz, vector<int> &par)
{
    int xx = find(x, par);
    int yy = find(y, par);
    if (xx != yy)
    {
        if (sz[xx] >= sz[yy])
        {
            sz[xx] += sz[yy];
            par[yy] = xx;
        }
        else
        {
            sz[yy] += sz[xx];
            par[xx] = yy;
        }
    }
}
 
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> par(n + 1, 0);
    vector<int> sz(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
 
    vector<vector<int>> dp(11, vector<int>(n + 11, 0));
 
    while (q)
    {
        int i, d, k;
        cin >> i >> d >> k;
        dp[d][i] = max(dp[d][i], k);
        q--;
    }
 
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= 10; i++)
        {
            if (dp[i][j] > 0)
            {
                dp[i][j + i] = max(dp[i][j + i], dp[i][j] - 1);
                int x = j;
                int y = j + i;
                uni(x, y, sz, par);
            }
        }
    }
    int ans = 0;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x = find(i, par);
        if (!vis[x])
        {
            ans++;
            vis[x] = 1;
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
