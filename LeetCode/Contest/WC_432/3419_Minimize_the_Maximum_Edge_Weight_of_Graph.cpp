#include <bits/stdc++.h>

using namespace std;

// << ,

int dfs(int node, int maxWeight, vector<vector<pair<int, int>>> &reverseAdjList, vector<int> &visited)
{
    visited[node] = 1;
    int count = 1;

    for (auto &[neighbor, weight] : reverseAdjList[node])
    {
        if (weight <= maxWeight && !visited[neighbor])
        {
            count += dfs(neighbor, maxWeight, reverseAdjList, visited);
        }
    }

    return count;
}

int minMaxWeight(int numNodes, vector<vector<int>> &edges, int threshold)
{
    vector<vector<pair<int, int>>> reverseAdjList(numNodes);

    for (auto &edge : edges)
    {
        int from = edge[0], to = edge[1], weight = edge[2];
        reverseAdjList[to].emplace_back(from, weight);
    }

    int left = 1, right = 1000001;

    while (left < right)
    {
        
        int mid = (left + right) / 2;
        vector<int> visited(numNodes, 0);

        if (dfs(0, mid, reverseAdjList, visited) == numNodes)
            right = mid;
        else
            left = mid + 1;
    }

    return (left == 1000001) ? -1 : left;
}
