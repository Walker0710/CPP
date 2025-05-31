#include <bits/stdc++.h>

using namespace std;

// << ,

long long solve(long long curr, long long prev, long long sign, long long dist, unordered_map<int, list<int>> &adj, vector<int> &nums, long long k, vector<vector<vector<long long>>> &dp)
{
    if (dist > 50)
        dist = 50;

    if (dp[sign + 1][dist + 1][curr] != INT_MIN)
    {
        return dp[sign + 1][dist + 1][curr];
    }

    // koi inversion nhi hua
    if (dist == -1)
    {
        long long a = -nums[curr];
        long long b = nums[curr];

        for (auto &neigh : adj[curr]) // invert kar rhe
        {
            if (neigh != prev)
            {
                a = a + solve(neigh, curr, -1, 1, adj, nums, k, dp);
            }
        }

        for (auto &neigh : adj[curr]) // invert nhi kar rhe
        {
            if (neigh != prev)
            {
                b = b + solve(neigh, curr, 0, -1, adj, nums, k, dp);
            }
        }

        return dp[sign + 1][dist + 1][curr] = max(a, b);
    }

    // inversion is allowedd
    if (dist >= k)
    {
        long long a = -nums[curr] * sign;
        long long b = nums[curr] * sign;

        for (auto &neigh : adj[curr]) // invert kar rhe
        {
            if (neigh != prev)
            {
                a = a + solve(neigh, curr, -1 * sign, 1, adj, nums, k, dp);
            }
        }

        for (auto &neigh : adj[curr]) // invert nhi kar rhe
        {
            if (neigh != prev)
            {
                b = b + solve(neigh, curr, sign, dist + 1, adj, nums, k, dp);
            }
        }

        return dp[sign + 1][dist + 1][curr] = max(a, b);
    }

    // inversion allowed nhi h
    if (dist < k)
    {
        long long b = nums[curr] * sign;

        for (auto &neigh : adj[curr]) // invert nhi kar rhe
        {
            if (neigh != prev)
            {
                b = b + solve(neigh, curr, sign, dist + 1, adj, nums, k, dp);
            }
        }

        return dp[sign + 1][dist + 1][curr] = b;
    }

    return 0;
}

long long subtreeInversionSum(vector<vector<int>> &edges, vector<int> &nums, int k)
{
    int n = edges.size() + 1;
    unordered_map<int, list<int>> adj;

    vector<vector<vector<long long>>> dp(3, vector<vector<long long>>(52, vector<long long>(n + 1, INT_MIN)));

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = solve(0, -1, 0, -1, adj, nums, k, dp);

    return ans;
}