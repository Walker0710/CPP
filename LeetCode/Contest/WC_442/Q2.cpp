#include <bits/stdc++.h>

using namespace std;

// << ,

bool isInter(vector<int> &a, vector<int> &b, int k)
{
    unordered_set<int> one(a.begin(), a.end());
    unordered_set<int> two(b.begin(), b.end());

    // int cnt = 0;

    // for(auto &yoo : one) {
    //     if(two.find(yoo) != two.end()) {
    //         cnt++;
    //     }
    // }

    // return cnt >= k;
    int cnt = 0;

    if (one.size() > two.size())
        return isInter(b, a, k);

    for (const auto &x : one)
    {
        if (two.count(x))
        {
            cnt++;
            if (cnt >= k)
                return true;
        }
    }

    return false;
}

void dfs(int i, unordered_map<int, list<int>> &adj, vector<bool> &visi)
{
    visi[i] = true;

    for (auto &neigh : adj[i])
    {
        if (!visi[neigh])
        {
            dfs(neigh, adj, visi);
        }
    }
}

int numberOfComponents(vector<vector<int>> &properties, int k)
{
    int n = properties.size();
    int m = properties[0].size();
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (isInter(properties[i], properties[j], k))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int cnt = 0;

    vector<bool> visi(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visi[i])
        {
            dfs(i, adj, visi);
            cnt++;
        }
    }

    return cnt;
}

class UnionFind
{
public:
    char root[100], rank[100], components;
    UnionFind(int N) : components(N)
    {
        iota(root, root + N, 0);
        fill(rank, rank + N, 1);
    }

    int Find(int x)
    {
        return (x == root[x]) ? x : root[x] = Find(root[x]);
    }

    bool Union(int x, int y)
    { // Union by rank
        int rX = Find(x), rY = Find(y);
        if (rX == rY)
            return 0;
        if (rank[rX] > rank[rY])
            swap(rX, rY);
        root[rX] = rY;
        if (rank[rX] == rank[rY])
            rank[rY]++;
        components--;
        return 1;
    }
};

class Solution
{
public:
    static int intersect(const auto &A, const auto &B)
    {
        return (A & B).count();
    }

    static int numberOfComponents(vector<vector<int>> &properties, int k)
    {
        const int n = properties.size(), m = properties[0].size();
        vector<bitset<101>> A(n, 0);
        int i = 0;
    
        for (auto &a : properties)
        {
            for (int x : a)
                A[i][x] = 1;
            i++;
        }

        UnionFind G(n);
        int components = n;
    
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                const auto &X = A[i];
                const auto &Y = A[j];
                if (intersect(X, Y) >= k)
                {
                    G.Union(i, j);
                }
            }
        }
        return G.components;
    }
};