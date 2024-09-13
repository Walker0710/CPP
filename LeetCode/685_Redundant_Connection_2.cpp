#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <string>

using namespace std;

// 1st
unordered_map<int, unordered_set<int>> adj;
vector<int> indegree;
int n;

void dfs(int node, vector<bool> &vis)
{
    if (vis[node])
        return;

    vis[node] = 1;

    for (auto i : adj[node])
        dfs(i, vis);
}

bool isRooted()
{
    int root = -1;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            root = i;
            break;
        }
    }

    if (root == -1)
        return 0;

    vector<bool> vis(n + 1, 0);

    dfs(root, vis);

    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            return 0;

    return true;
}
vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
{

    n = edges.size();
    indegree.resize(n + 1, 0);

    for (auto i : edges)
    {
        adj[i[0]].insert(i[1]);
        indegree[i[1]]++;
    }

    vector<int> ans;

    for (auto i : edges)
    {
        adj[i[0]].erase(i[1]);
        indegree[i[1]]--;

        if (isRooted())
        {
            ans = {i[0], i[1]};
        }

        adj[i[0]].insert(i[1]);
        indegree[i[1]]++;
    }

    return ans;
}

// leet code
class UnionFind
{
public:
    vector<int> parent; 
    vector<int> rank;   

    UnionFind(int n) : parent(n), rank(n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    bool unite(int a, int b)
    {
        int rootA = find(a); 
        int rootB = find(b);

        if (rootA == rootB)
            return false;

        if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
        }
        else if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else
        {
            parent[rootA] = rootB;
            rank[rootB]++;
        }

        return true;
    }

    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]]; 
            x = parent[x];                 
        }
        return x; 
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
{
    int numEdges = edges.size();
    vector<int> directParents(numEdges + 1); 

    for (int i = 0; i <= numEdges; ++i)
        directParents[i] = i;

    UnionFind uf(numEdges + 1); // UnionFind instance to manage disjoint sets
    int conflictEdgeIdx = -1;   // Index of the conflicting edge
    int cycleEdgeIdx = -1;      // Index of the edge causing a cycle

    // Iterate over the edges to find any cycle or conflict.
    for (int i = 0; i < numEdges; ++i)
    {
        int u = edges[i][0]; 
        int v = edges[i][1]; 

        // If v already has a parent, we have found a conflict.
        if (directParents[v] != v)
        {
            conflictEdgeIdx = i;
        }
        else
        {
            // Assign parent for v.
            directParents[v] = u;
            // If the union operation indicates a cycle, record the current edge index.
            if (!uf.unite(u, v))
            {
                cycleEdgeIdx = i;
            }
        }
    }

    if (conflictEdgeIdx == -1)
    {
        return edges[cycleEdgeIdx];
    }

    // If a cycle exists when a conflict is found, we return the previous edge that caused the cycle with the conflicting node.
    int v = edges[conflictEdgeIdx][1];
    if (cycleEdgeIdx != -1)
    {
        return {directParents[v], v};
    }
    // If there's only a conflict without a cycle, we return the conflicting edge.
    return edges[conflictEdgeIdx];
}

