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

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{

    for (int i = 0; i < n; i++)
    {

        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{

    if (parent[node] == node)
        return node;

    return findParent(parent, parent[node]);
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

bool isBipartite(vector<vector<int>> &graph)
{

    int parentX = -2;
    int parentY = -1;

    int n = graph.size();

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, graph.size());

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

                    unionSet(neigh, parentY, parent, rank);
                }

                if (parent[node] == parentY)
                {

                    unionSet(neigh, parentX, parent, rank);
                }
            }

            visited[neigh] = true;
        }

        visited[node] = true;
    }
    return true;
}

int main()
{

    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

    if (isBipartite(graph))
    {
        cout << "Graph is Bipartite" << endl;
    }

    else
    {
        cout << "Graph is not Bipartite" << endl;
    }

    return 0;
}

//2nd ans superior
bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), -1);
    queue<int> q;

    for (int i = 0; i < graph.size(); i++)
    {
        q.push(i);

        if (color[i] >= 0)
        continue;

        color[i] = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto neigh : graph[curr])
            {
                if (color[neigh] == color[curr])
                return false;

                else if (color[neigh] >= 0)
                continue;

                color[neigh] = !color[curr];
                q.push(neigh);
            }
        }
    }
    return true;
}
