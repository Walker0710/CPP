#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>

using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<int> degree(n);
    unordered_map<int, list<int>> adj;

    for (auto i : roads)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);

        degree[i[0]]++;
        degree[i[1]]++;
    }

    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int rank = degree[i] + degree[j];

            if (adj[i].end() != find(adj[i].begin(), adj[i].end(), j))
            rank -= 1;

            ans = max(ans, rank);
        }
    }

    return ans;
}