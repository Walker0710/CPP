#include <bits/stdc++.h>

using namespace std;

// << ,

vector<pair<int, int>> change;
vector<int> adj[100000];

void dfs(int node, int original, vector<int> &parent, string &s)
{
    if (s[original] == s[node])
    {
        change.push_back({original, node});
        return;
    }

    if (node == 0)
        return;

    dfs(parent[node], original, parent, s);
}

void countChildren(int i, vector<int> &ans)
{
    for (auto child : adj[i])
    {
        countChildren(child, ans);
        ans[i] += ans[child];
    }
}

vector<int> findSubtreeSizes(vector<int> &parent, string s)
{
    int n = parent.size();
    vector<int> res(n, 1);

    for (int i = 1; i < n; i++)
    {
        dfs(parent[i], i, parent, s);
    }

    for (auto itr : change)
        parent[itr.first] = itr.second;

    for (int i = 1; i < n; i++)
    {
        adj[parent[i]].push_back(i);
    }

    countChildren(0, res);

    return res;
}









void calculateSubTreeSizes(int currNode, vector<vector<int>> &tree, string &s, unordered_map<char, vector<int>> &state, vector<int> &res)
{
    res[currNode] = 1;
    state[s[currNode]].push_back(currNode);

    for (int childNode : tree[currNode])
    {
        calculateSubTreeSizes(childNode, tree, s, state, res);

        if (!state[s[childNode]].empty())
        {
            int ancestorNode = state[s[childNode]].back();
            res[ancestorNode] += res[childNode];
        }
        else
        {
            res[currNode] += res[childNode];
        }
    }

    state[s[currNode]].pop_back();
}

vector<int> findSubtreeSizes(vector<int> &parent, string s)
{
    vector<vector<int>> tree(s.length());
    vector<int> res(s.length(), 0);

    for (int i = 1; i < parent.size(); i++)
    {
        tree[parent[i]].push_back(i);
    }

    unordered_map<char, vector<int>> state;
    calculateSubTreeSizes(0, tree, s, state, res);

    return res;
}