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

void dfs(int node, int parent, int &timer, vector<int> &discovered, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> adj, unordered_map<int, bool> &vis) {

    vis[node] = true;
    discovered[node] = low[node] = timer++;

    for(auto neigh:adj[node]) {

        if(neigh == parent) 
        continue;

        if(!vis[neigh]) {

            dfs(neigh, node, timer, discovered, low, result, adj, vis);
            low[node] = min(low[node], low[neigh]);

            //check edge is bridge
            if(low[neigh] > discovered[node]) {

                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neigh);
                result.push_back(ans);
            }
        }

        else {

            //back edge
            low[node] = min(low[node], discovered[neigh]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e, int &disconnect) {

    unordered_map<int, list<int>> adj;

    for(int i = 0;  i<edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> discovered(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;

    for(int i = 0; i<v; i++) {

        discovered[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;

    //dfs
    for(int i = 0; i<v; i++) {

        if(!vis[i]) {

            disconnect++;
            dfs(i, parent, timer, discovered, low, result, adj, vis);
        }
    }

    return result;
}

void removeElement(vector<vector<int>> bridges, vector<vector<int>> &connections) {

    vector<int> index;

    for(int i = 0; i<bridges.size(); i++) {

        for(int j = 0; j<connections.size(); j++) {

            if(bridges[i][0] == connections[j][0] && bridges[i][1] == connections[j][1]) {

                index.push_back(j);
            }
        }
    }

    for(int i = 0; i<index.size(); i++) {

        connections.erase(connections.begin() + index[i]);
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {

    int edges = connections.size();
    int disconnect = 0;

    vector<vector<int>> bridges = findBridges(connections, n, connections.size(), disconnect);

    int NumberOfBridges = bridges.size();

    int waste = 0;

    while(NumberOfBridges != connections.size()) {

        if(NumberOfBridges == 0) {

            connections.erase(connections.begin());
        }

        else {

            removeElement(bridges, connections);
        }

        bridges = findBridges(connections, n, connections.size(), waste);
        NumberOfBridges = bridges.size();
    }

    int yo = edges - NumberOfBridges;

    if(yo >= disconnect - 1) {

        return disconnect - 1;
    }

    return -1;
}

//2nd attempt
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<vector<int>> connections) {

    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i<connections.size(); i++) {

        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(make_pair(v,1));
        adj[v].push_back(make_pair(u,1));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i = 0; i<=n; i++) {

        key[i] = INT32_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    //algo staring here
    key[1] = 0;
    parent[1] = -1;

    for(int i = 1; i<n; i++) {

        int mini = INT32_MAX;
        int u;

        //finding min wli node
        for(int v = 1; v<=n; v++) {

            if(mst[v] == false && key[v] < mini) {

                u = v;
                mini = key[v];
            }
        }

        //mark min wli node ko true
        mst[u] = true;

        //check its adjacent nodes
        for(auto it:adj[u]) {

            int v = it.first;
            int w = it.second;

            if(mst[v] = false && w < key[v]) {

                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for(int i = 2; i<=n; i++) {

        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {

    visited[node] = true;

    for(auto i:adj[node]) {

        if(!visited[i]) {

            dfs(i, visited, adj);
        }
    }
}

int depthFirstSearch(int V, int E, vector<vector<int>> &edges) {

    unordered_map<int, list<int>> adj;

    for(int i = 0; i<edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    unordered_map<int, bool> visited;

    for(int i = 0; i<V; i++) {

        if(!visited[i]) {

            count++;
            dfs(i, visited, adj);
        }
    }

    return count;
}

int makeConnected(int n, vector<vector<int>>& connections) {

    vector<pair<pair<int, int>, int>> MST = calculatePrimsMST(n, connections.size(), connections);
    int edgesInMST = MST.size();

    int NoDC = depthFirstSearch(n, connections.size(), connections);

    int yo = connections.size() - edgesInMST;

    if(yo >= NoDC - 1) {

        return NoDC - 1;
    }

    return -1;
}
