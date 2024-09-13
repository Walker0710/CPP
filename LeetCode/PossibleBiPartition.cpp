#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>

using namespace std;

// 1st approch - myself
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

void unionSet(int u, int v, vector<int> &parent)
{
    parent[v] = u;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{

    if (dislikes.size() == 0)
        return true;

    sort(dislikes.begin(), dislikes.end());

    vector<int> parent(n + 1);
    vector<int> rank(n + 1);

    makeSet(parent, rank, n);

    int parent1 = findParent(parent, dislikes[0][0]);
    int parent2 = findParent(parent, dislikes[0][1]);

    for (int i = 1; i < dislikes.size(); i++)
    {

        int u = dislikes[i][0];
        int v = dislikes[i][1];

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        if (parentU == parentV)
            return false;

        else if (parentU == parent1)
            unionSet(parent2, parentV, parent);

        else if (parentU == parent2)
            unionSet(parent1, parentV, parent);

        else if (parentV == parent1)
            unionSet(parent2, parentU, parent);

        else if (parentV == parent2)
            unionSet(parent1, parentU, parent);

        else
        {

            unionSet(parent1, parentU, parent);
            unionSet(parent2, parentV, parent);
        }
    }

    return true;
}

// 2nd approch - myself
bool isBipartite(unordered_map<int, list<int>> &graph, int n)
{
    vector<int> color(n + 1, -1);
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);

        if (color[i] >= 0)
            continue;

        color[i] = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto neigh : graph[i])
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

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{

    if (dislikes.size() == 0)
        return true;

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < dislikes.size(); i++)
    {
        adj[dislikes[i][0]].push_back(dislikes[i][1]);
        adj[dislikes[i][1]].push_back(dislikes[i][0]);
    }

    bool ans = isBipartite(adj, n);

    return ans;
}

// 3rd - leetcode soln
bool checkbfs(vector<int> &cols, unordered_map<int, vector<int>> &g, queue<int> &q)
{
    int curr = 1;
    while (!q.empty())
    {

        int size = q.size();

        for (int k = 0; k < size; k++)
        {

            vector<int> &a = g[q.front()];
            q.pop();
            for (int i : a)
            {

                if (cols[i] != -1)
                {
                    if (cols[i] == abs(curr - 1))
                    {
                        // its okay
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    cols[i] = abs(curr - 1);
                    q.push(i);
                }
            }
        }
        curr = abs(curr - 1);
    }
    return true;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{

    if (dislikes.empty())
        return true;

    unordered_map<int, vector<int>> g;
    for (vector<int> &a : dislikes)
    {
        g[a[0]].push_back(a[1]);
        g[a[1]].push_back(a[0]);
    }

    vector<int> cols(1 + n, -1);
    queue<int> q;

    bool ans = true;

    int i = 1;
    while (i <= n)
    {
        if (cols[i] == -1)
        {
            q.push(i);
            cols[i] = 1; // initializing the colour of first element with 1
            ans &= checkbfs(cols, g, q);
        }
        i++;
    }
    return ans;
}
