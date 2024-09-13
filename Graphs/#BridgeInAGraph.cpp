#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>

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

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

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

            dfs(i, parent, timer, discovered, low, result, adj, vis);
        }
    }

    return result;
}