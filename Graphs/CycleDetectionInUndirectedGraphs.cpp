#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

// by BFS
bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {

    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {

        int front = q.front();
        q.pop();

        for(auto neigh:adj[front]) {

            if(visited[neigh] == true && neigh != parent[front])
            return true;

            else if(!visited[neigh]) {

                q.push(neigh);
                visited[neigh] = 1;
                parent[neigh] = front;
            }
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) {

    unordered_map<int, list<int>> adj;

    for(int i = 0; i<edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visitedl;

    for(int i = 0; i<n; i++) {

        if(!visitedl[i]) {

            bool ans = isCyclicBFS(i, visitedl, adj);
            if(ans == 1) 
            return "Yes";
        }
    }
    return "No";
}

// by DFS
bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {

    visited[node] = true;

    for(auto neigh:adj[node]) {

        if(!visited[neigh]) {

            bool cycleDetected = isCyclicDFS(neigh, node, visited, adj);
            if(cycleDetected)
            return true;
        }

        else if(neigh != parent)
        return true;
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) {

    unordered_map<int, list<int>> adj;

    for(int i = 0; i<edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visitedl;

    for(int i = 0; i<n; i++) {

        if(!visitedl[i]) {

            bool ans = isCyclicDFS(i, -1, visitedl, adj);
            if(ans == 1) 
            return "Yes";
        }
    }
    return "No";
}