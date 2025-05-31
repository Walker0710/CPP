#include <bits/stdc++.h>

using namespace std;

// << ,

const int MOD = 1e9 + 7;

void dfs(int u, int par, int lvl, vector<int> &levels, vector<vector<int>> &graph, vector<vector<int>> &LCA, vector<bool> &visited)
{
    visited[u] = true;
    levels[u] = lvl;
    LCA[u][0] = par;

    for (auto &v : graph[u])
    {
        if (!visited[v])
        {
            dfs(v, u, lvl + 1, levels, graph, LCA, visited);
        }
    }
}

void init(int n, int maxN, vector<vector<int>> &LCA)
{
    for (int i = 1; i <= maxN; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (LCA[j][i - 1] != -1)
            {
                int par = LCA[j][i - 1];
                LCA[j][i] = LCA[par][i - 1];
            }
        }
    }
}

int findLCA(int a, int b, int maxN, vector<int> &levels, vector<vector<int>> &LCA)
{
    if (levels[a] > levels[b])
        swap(a, b);

    int d = levels[b] - levels[a];

    while (d > 0)
    {
        int jump = min((int)log2(d), maxN); 
        if (LCA[b][jump] == -1)
            return -1;
        b = LCA[b][jump];
        d -= (1 << jump);
    }

    if (LCA[a][0] == -1 || LCA[b][0] == -1)
        return -1;

    if (a == b)
        return a;

    for (int i = maxN; i >= 0; i--)
    {
        if (LCA[a][i] != -1 && LCA[a][i] != LCA[b][i])
        {
            a = LCA[a][i], b = LCA[b][i];
        }
    }

    return LCA[a][0];
}

int getDistance(int u, int v, int maxN, vector<int> &levels, vector<vector<int>> &LCA)
{
    int lca = findLCA(u, v, maxN, levels, LCA);

    if (lca == -1)
        return -1;

    return levels[u] + levels[v] - 2 * levels[lca];
}

vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
{
    vector<vector<int>> graph(n);
    int m = queries.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(nums[i] - nums[j]) <= maxDiff)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int maxN = log2(n) + 1;

    vector<int> levels(n);
    vector<vector<int>> LCA(n, vector<int>(maxN, -1));

    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, -1, 0, levels, graph, LCA, visited);
        }
    }

    init(n, maxN, LCA);

    vector<int> ans(m);

    for (int i = 0; i < m; i++)
    {
        int u = queries[i][0] - 1, v = queries[i][1] - 1;
        ans[i] = getDistance(u, v, maxN, levels, LCA);
    }

    return ans;
}