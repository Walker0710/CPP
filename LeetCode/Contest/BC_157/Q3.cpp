#include <bits/stdc++.h>

using namespace std;

// << ,

const int MOD = 1e9 + 7;

long long modPow(long long base, long long exp, int mod)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int assignEdgeWeights(vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    int ans = 0;
    unordered_set<int> visited;
    queue<int> q;
    q.push(1);
    visited.insert(1);

    while (!q.empty())
    {
        int len = q.size();

        for (int i = 0; i < len; i++)
        {
            int topp = q.front();
            q.pop();

            for (auto neigh : adj[topp])
            {
                if (!visited.count(neigh))
                {
                    visited.insert(neigh);
                    q.push(neigh);
                }
            }
        }

        ans++;
    }

    if (ans == 0)
        return 0;

    return modPow(2, ans - 2, MOD);
}