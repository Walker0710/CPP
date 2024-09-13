#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>

using namespace std;

// 1st approch but TLE at 66th/71
void dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, int count, int &mini)
{

    visited[node] = true;

    for (auto neigh : adj[node])
    {

        if (!visited[neigh])
        {

            dfs(neigh, adj, visited, count + 1, mini);
        }
    }

    if (mini < count)
    {

        mini = count;
    }
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n);
    int minimum = INT_MAX;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            visited[j] = false;
        }

        int mini = INT_MIN;
        dfs(i, adj, visited, 0, mini);

        if (minimum == mini)
        {
            ans.push_back(i);
        }

        else if (minimum > mini)
        {
            ans.clear();
            ans.push_back(i);
            minimum = mini;
        }
    }
    return ans;
}

// 2nd
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1)
    return {0}; 

    vector<int> degree(n, 0);
    vector<vector<int>> graph(n);
    
    for (auto &edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    queue<int> leafQueue;
    
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
        leafQueue.push(i);
    }

    int remainingNodes = n;

    while (remainingNodes > 2)
    {
        int leafCount = leafQueue.size();
        remainingNodes -= leafCount;

        for (int i = 0; i < leafCount; i++)
        {
            int leaf = leafQueue.front();
            leafQueue.pop();

            for (int neighbor : graph[leaf])
            {
                if (--degree[neighbor] == 1)
                leafQueue.push(neighbor);
            }
        }
    }

    vector<int> minHeightTrees;
    while (!leafQueue.empty())
    {
        minHeightTrees.push_back(leafQueue.front());
        leafQueue.pop();
    }
    return minHeightTrees;
}
