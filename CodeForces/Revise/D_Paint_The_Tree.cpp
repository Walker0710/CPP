#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

vector<int> shortestPath(unordered_map<int, list<int>> adj, int n, int m, int a, int b)
{
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(a);

    visited[a] = true;
    parent[a] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    vector<int> ans;
    int currentNode = b;
    ans.push_back(b);

    while (currentNode != a)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> shortest_path = shortestPath(adj, n, n - 1, a, b);
    vector<int> visi(n + 1);

    int root = shortest_path[shortest_path.size()/2];
    visi[root] = 1;
    int height = 0;

    queue<pair<int, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {

        pair<int, int> yoo = q.front();
        q.pop();
        height = max(height, yoo.second);

        for (auto node : adj[yoo.first])
        {
            if (!visi[node])
            {
                q.push({node, yoo.second + 1});
                visi[node] = 1;
            }
        }
    }

    cout << 2 * n - height << endl;
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

// 2nd approch
// vector<vector<int>> graph;
// vector<int> depth;

// void dfs(int x, int p)
// {
//     for (auto e : graph[x])
//     {
//         if (e != p)
//         {
//             depth[e] = depth[x] + 1;
//             dfs(e, x);
//         }
//     }
// }

// vector<int> path(int x, int p, int v)
// {
//     if (x == v)
//     {
//         return {x};
//     }

//     for (auto e : graph[x])
//     {
//         if (e != p)
//         {
//             vector<int> out = path(e, x, v);

//             if (out.size())
//             {
//                 out.push_back(x);
//                 return out;
//             }
//         }
//     }

//     return {};
// }

// signed main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;

//         int a, b;
//         cin >> a >> b;

//         graph = vector<vector<int>>(n + 1);

//         for (int i = 0; i < n - 1; i++)
//         {
//             int u, v;
//             cin >> u >> v;

//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }

//         vector<int> out = path(a, 0, b);
//         reverse(all(out));

//         int sz = out.size();

//         int v = out[(sz+1)/2 - 1];

//         depth = vector<int> (n+1);
//         dfs(v, 0);

//         int ma = *max_element(all(depth));

//         cout << 2*(n-1) - ma + sz/2 << endl;
//     }
// }