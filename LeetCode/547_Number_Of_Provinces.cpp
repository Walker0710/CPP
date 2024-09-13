#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<limits.h>

using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n) {             

    for(int i = 0; i<n; i++) {

        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {

    if(parent[node] == node)
    return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {

    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) 
    parent[u] = v;

    else if(rank[v] < rank[u]) 
    parent[v] = u;

    else {

        parent[v] = u;
        rank[u]++;
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {

    int n = isConnected.size();

    vector<pair<int, int>> edges(n);

    for(int i = 0; i<n; i++) {

        for(int j = 0; j<n; j++) {

            if(isConnected[i][j] == 1) {

                edges.push_back({i,j});
            }
        }
    }

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);

    for(int i = 0; i<edges.size(); i++) {

        int u = findParent(parent, edges[i].first);
        int v = findParent(parent, edges[i].second);

        if(u != v) {

            unionSet(u, v, parent, rank);
        }
    }

    set<int> yo;

    for(int i = 0; i<n; i++) {

        int yo1 = findParent(parent, i);
        yo.insert(yo1);
    }

    return yo.size();
}