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

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// path compression
int findParent1(vector<int> &parent, int node)
{
    if (parent[node] == node)
    return node;

    return parent[node] = findParent1(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent1(parent, u);
    v = findParent1(parent, v);

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

int makeConnected(int n, vector<vector<int>> &connections)
{
    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);
    int count = 0;

    for (int i = 0; i < connections.size(); i++)
    {
        int u = findParent1(parent, connections[i][0]); 
        int v = findParent1(parent, connections[i][1]);

        if (u != v)
        unionSet(u, v, parent, rank);

        else
        count++;
    }

    unordered_set<int> s;
    
    for(int i = 0; i<n; i++) {
        int u = findParent1(parent, i);
        s.insert(u);
    }

    if(s.size() - 1 > count) {
        return -1;
    }

    return s.size() - 1;
}