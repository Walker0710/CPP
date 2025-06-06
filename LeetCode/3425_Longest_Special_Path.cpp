#include <bits/stdc++.h>

using namespace std;

// << ,

pair<int, int> ans;
vector<vector<pair<int, int>>> children;

void buildTree(int node, int parent, unordered_map<int, list<pair<int, int>>> &adj)
{
    for (auto &neigh : adj[node])
    {
        if (neigh.first != parent)
        {
            children[node].push_back(neigh);
            buildTree(neigh.first, node, adj);
        }
    }
}

void DFS(int node, int MaxDept, int noNode, vector<int> &nums, unordered_set<int> &st)
{
    st.insert(nums[node]);

    if ((ans.first < MaxDept) ||
        (ans.first == MaxDept && ans.second > noNode) ||
        (ans.first == 0 && ans.second == INT_MAX)) // handle first single node path
    {
        ans.first = MaxDept;
        ans.second = noNode;
    }

    for (auto &neigh : children[node])
    {
        if (st.find(nums[neigh.first]) == st.end())
        {
            DFS(neigh.first, MaxDept + neigh.second, noNode + 1, nums, st);
        }
    }

    st.erase(nums[node]); // Backtrack
}

vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
{
    unordered_map<int, list<pair<int, int>>> adj;
    int n = nums.size();
    ans = {0, INT_MAX}; // very important to initialize like this
    children = vector<vector<pair<int, int>>>(n);

    for (auto &edge : edges)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    // Build children tree rooted at node 0
    buildTree(0, -1, adj);

    // Now run DFS from every ancestor (including subtree roots)
    // but only downward
    for (int startNode = 0; startNode < n; startNode++)
    {
        unordered_set<int> st;
        DFS(startNode, 0, 1, nums, st);
    }

    return {ans.first, ans.second};
}

// 2nd approch

int maxL = 0;
int nodes = 1;

void help(vector<pair<int, int>> &a, vector<int> &b)
{
    int l = 0, n = b.size();
    vector<int> s(50001, 0);
    s[b[a[0].first]] = 1;

    for (int r = 1; r < a.size(); r++)
    {
        pair<int, int> t = a[r];
        int i = t.first;
        int v = b[i];

        while (s[v] > 0)
        {
            s[(b[a[l++].first])]--;
        }

        s[v] = 1;

        if (a[r].second - a[l].second > maxL)
        {
            maxL = a[r].second - a[l].second;
            nodes = r - l + 1;
        }

        else if (a[r].second - a[l].second == maxL)
        {
            nodes = min(nodes, r - l + 1);
        }
    }
}

void dfs(vector<vector<pair<int, int>>> &g, vector<int> &b, vector<pair<int, int>> &a, int par)
{
    pair<int, int> t = a.back();
    int u = t.first, l = t.second;
    bool isLeaf = true;

    for (int i = 0; i < g[u].size(); i++)
    {
        if (g[u][i].first != par)
        {
            isLeaf = false;
            a.push_back({g[u][i].first, g[u][i].second + l});
            dfs(g, b, a, u);
            a.pop_back();
        }
    }

    if (isLeaf)
    {
        help(a, b);
    }
}

vector<int> longestSpecialPath(vector<vector<int>> &e, vector<int> &a)
{
    int n = a.size();
    vector<vector<pair<int, int>>> g(n);

    for (vector<int> &t : e)
    {
        g[t[0]].push_back({t[1], t[2]});
        g[t[1]].push_back({t[0], t[2]});
    }

    vector<pair<int, int>> temp;
    temp.push_back({0, 0});

    dfs(g, a, temp, -1);

    return {maxL, nodes};
}

// 3d approch

pair<int, int> res{0, 1};
int depth[50001] = {};

void dfs(int i, int p, vector<vector<array<int, 2>>> &al, vector<int> &nums, int left, int cur_depth, vector<int> &ps)
{
    // int prev_depth = exchange(depth[nums[i]], cur_depth);
   
    int prev_depth = depth[nums[i]];
    depth[nums[i]] = cur_depth;
    left = max(left, prev_depth);
    res = min(res, {-(ps.back() - ps[left]), cur_depth - left});

    for (auto &[j, l] : al[i])
    {
        if (j != p)
        {
            ps.push_back(ps.back() + l);
            dfs(j, i, al, nums, left, cur_depth + 1, ps);
            ps.pop_back();
        }
    }

    depth[nums[i]] = prev_depth;
}

vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
{
    vector<vector<array<int, 2>>> al(nums.size());

    for (const auto &e : edges)
    {
        al[e[0]].push_back({e[1], e[2]});
        al[e[1]].push_back({e[0], e[2]});
    }

    dfs(0, -1, al, nums, 0, 1, vector<int>() = {0});

    return {-res.first, res.second};
}