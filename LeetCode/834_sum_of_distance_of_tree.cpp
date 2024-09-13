#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <set>
#include <numeric>

using namespace std;

// dp[curr] = dp[prev] - nodes in the subtree of curr + (n-nodes in the subtree of curr).

void dfs1(int node, int parent, vector<vector<int>> &adj, vector<int> &subtreeSize, vector<int> &distSum)
{
    subtreeSize[node] = 1;
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
        dfs1(neighbor, node, adj, subtreeSize, distSum);
        subtreeSize[node] += subtreeSize[neighbor];
        distSum[node] += distSum[neighbor] + subtreeSize[neighbor];
    }
}

void dfs2(int node, int parent, vector<vector<int>> &adj, vector<int> &subtreeSize, vector<int> &distSum, vector<int> &ans, int n)
{
    ans[node] = distSum[node];
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;

        distSum[neighbor] = distSum[node] - subtreeSize[neighbor] + (n - subtreeSize[neighbor]);

        dfs2(neighbor, node, adj, subtreeSize, distSum, ans, n);
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for (const auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> subtreeSize(n, 0);
    vector<int> distSum(n, 0);
    vector<int> ans(n, 0);

    dfs1(0, -1, adj, subtreeSize, distSum);
    dfs2(0, -1, adj, subtreeSize, distSum, ans, n);

    return ans;
}

void dfs(vector<int> adj[], int n, int node, int prev, vector<int> &height, vector<int> &subtree)
{
    subtree[node]++;
    for (auto &ele : adj[node])
    {
        if (ele != prev)
        {
            height[ele] = 1 + height[node];
            dfs(adj, n, ele, node, height, subtree);
            subtree[node] += subtree[ele];
        }
    }
}

void rec(vector<int> adj[], int n, int node, int prev, vector<int> &subtree, vector<int> &dp)
{
    for (auto &ele : adj[node])
    {
        if (ele != prev)
        {
            dp[ele] = dp[node] - subtree[ele] + (n - subtree[ele]);
            rec(adj, n, ele, node, subtree, dp);
        }
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    for (auto &ele : edges)
    {
        int u = ele[0], v = ele[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> height(n, 0), subtree(n, 0); 
    vector<int> dp(n, 0);                    
    dfs(adj, n, 0, -1, height, subtree);
    for (int i = 0; i < n; i++)
        dp[0] += height[i];
    rec(adj, n, 0, -1, subtree, dp);
    return dp;
}