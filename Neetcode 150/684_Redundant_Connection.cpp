#include <bits/stdc++.h>

using namespace std;

// << ,

int findParent(vector<int> &parent, int node) {
    if(parent[node] == node)
    return node;

    return findParent(parent, parent[node]);
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    if(rank[u] < rank[v]) 
    parent[u] = v;

    else if(rank[v] < rank[u]) 
    parent[v] = u;

    else {
        parent[v] = u;
        rank[u]++;
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;

    vector<int> parent(n);
    vector<int> rank(n);
    vector<int> ans;

    makeSet(parent, rank, n);

        for(int i = 0; i<n-1; i++) {

        int first = edges[i][0];
        int second = edges[i][1];

        int firstParent = findParent(parent, first);
        int secondParent = findParent(parent, second);

        if(firstParent == secondParent) {

            ans = {first, second};
        }

        else {

            unionSet(firstParent, secondParent, parent, rank);
        }
    }

    return ans;
}