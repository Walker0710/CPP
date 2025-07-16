#include <bits/stdc++.h>

using namespace std;

// << ,

bool cmp(vector<int> &a, vector<int> &b)
{

    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{

    for (int i = 0; i < n; i++)
    {

        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{ // studies ye btati h ki findParent ya unionSet wle fn ki time complexity nearly constant hoti h so complexity of whole Kruskal algo mlog(m)
  // where m is total number of edges
    if (parent[node] == node)
        return node;

    return findParent(parent, parent[node]);
}

// path compression
int findParent1(vector<int> &parent, int node)
{

    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{

    u = findParent(parent, u);
    v = findParent(parent, v);

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

int main()
{

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);

    for (int i = 0; i < edges.size(); i++)
    {

        int u = findParent(parent, edges[i][0]); // jiski bhi rank kam h usko me jada rank wle ke niche le jata hu
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v)
        {

            unionSet(u, v, parent, rank);
        }
    }
}

class DSU
{
public:
    vector<int> size;
    vector<int> parent;
    vector<int> edges;

    DSU(int sz)
    {
        size.resize(sz + 1, 1);
        edges.resize(sz + 1, 0);
        parent.resize(sz + 1);

        for (int i = 0; i <= sz; i++)
        {
            parent[i] = i;
        }
    }

    int fp(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = fp(parent[u]);
    }

    void dsu(int u, int v)
    {
        int pu = fp(u), pv = fp(v);
        if (pu == pv)
        {
            edges[pu]++;
            return;
        }

        if (size[pu] >= size[pv])
        {
            edges[pu] += edges[pv] + 1;
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else
        {
            edges[pv] += edges[pu] + 1;
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }
};

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        DSU obj(n + 1);
        for (auto ed : edges)
        {
            obj.dsu(ed[0], ed[1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (obj.fp(i) == i && obj.edges[i] == ((obj.size[i] * (obj.size[i] - 1)) / 2))
            {
                res++;
            }
        }
        return res;
    }
};