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

void makeSet(vector<int> &parent, int n)
{

    for (int i = 0; i < n; i++)
    {

        parent[i] = i;
    }
}

int findParent(vector<int> &parent, int node)
{

    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent)
{

    u = findParent(parent, u);
    v = findParent(parent, v);

    parent[u] = v;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();

    int parentX = n + 1;
    int parentY = n + 2;

    vector<int> parent(n + 3);

    makeSet(parent, graph.size());

    parent[0] = parentX;
    parent[graph[0][0]] = parentY;

    unordered_map<int, bool> visited(n);
    visited[graph[0][0]] = true;

    for (int node = 0; node < graph.size(); node++)
    {

        for (auto neigh : graph[node])
        {

            if (parent[node] == parent[neigh])
            {

                return false;
            }

            else if (!visited[neigh])
            {

                if (parent[node] == parentX)
                {

                    unionSet(neigh, parentY, parent);
                }

                if (parent[node] == parentY)
                {

                    unionSet(neigh, parentX, parent);
                }
            }

            visited[neigh] = true;
        }

        visited[node] = true;
    }
    return true;
}

// approch 2 - coloring the node
bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> node_color(graph.size(), -1);
    queue<int> ordering;

    for (int i = 0; i < graph.size(); i++)
    {
        ordering.push(i);

        if (node_color[i] >= 0)
            continue;

        node_color[i] = 0;

        while (!ordering.empty())
        {
            int curr = ordering.front();
            ordering.pop();

            for (auto neighbor : graph[curr])
            {
                if (node_color[neighbor] == node_color[curr])
                    return false;

                else if (node_color[neighbor] >= 0)
                    continue;

                node_color[neighbor] = !node_color[curr];
                ordering.push(neighbor);
            }
        }
    }
    return true;
}

//3rd same approch but using dfs
bool dfs(int source, vector<vector<int>> &graph, vector<int> &visited, int color)
{
    visited[source] = color; // Assign color to the current node

    for (auto it : graph[source])
    {
        if (visited[it] == -1)
        {

            if (!dfs(it, graph, visited, 1 - color))
            {
                return false;
            }
        }
        else
        {

            if (visited[it] == visited[source])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> visited(V, -1); // -1 means unvisited, 0 and 1 for two groups

    // Perform DFS from each unvisited node
    for (int i = 0; i < V; ++i)
    {
        if (visited[i] == -1)
        {
            if (!dfs(i, graph, visited, 0))
            { // Start DFS with color 0
                return false;
            }
        }
    }
    return true;
}