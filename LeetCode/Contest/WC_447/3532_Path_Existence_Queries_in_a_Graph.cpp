#include <bits/stdc++.h>

using namespace std;

// << ,

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{

    for (int i = 0; i < n; i++)
    {

        parent[i] = i;
        rank[i] = 0;
    }
}

// path compression
int findParent1(vector<int> &parent, int node)
{

    if (parent[node] == node)
        return node;

    return parent[node] = findParent1(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{

    u = findParent1(parent, u);
    v = findParent1(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;

    else if (rank[v] < rank[u])
        parent[v] = u;

    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
{
    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(nums[i] - nums[i + 1]) <= maxDiff)
        {
            unionSet(i, i + 1, parent, rank);
        }
    }

    vector<bool> ans(queries.size());

    for (int i = 0; i < queries.size(); i++)
    {
        int x = queries[i][0];
        int y = queries[i][1];

        if (parent[x] == parent[y])
            ans[i] = true;

        else
        {
            ans[i] = false;
        }
    }

    return ans;
}


// 2nd approch
vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
{
    vector<int> group(n, 0);
    int currentGroup = 0;
    
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] - nums[i - 1] > maxDiff)
        {
            currentGroup++;
        }
        group[i] = currentGroup;
    }

    vector<bool> res;
    
    for (auto &q : queries)
    {
        int u = q[0], v = q[1];
        res.push_back(group[u] == group[v]);
    }
 
    return res;
}