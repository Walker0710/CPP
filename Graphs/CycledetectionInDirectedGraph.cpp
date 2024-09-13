#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

//using DFS
bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &DFSvisited, unordered_map<int, list<int>> &adj) {

    visited[node] = true;
    DFSvisited[node] = true;

    for(auto neigh:adj[node]) {

        if(!visited[neigh]) {

            bool cycleDetected = checkCycleDFS(neigh, visited, DFSvisited, adj);

            if(cycleDetected)
            return true;
        }

        else if(DFSvisited[neigh] == true)
        return true;
    }

    DFSvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    unordered_map<int, list<int>> adj;
    for(int i = 0; i<edges.size(); i++) {

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;

    for(int i = 0; i<n; i++) {
        
        if(!visited[i]) {

            bool cyclefound = checkCycleDFS(i, visited, DFSvisited, adj);

            if(cyclefound)
            return true;
        }
    }
    return false;
}

// using BFS
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    unordered_map<int, list<int>> adj;  //kitno ko ye point kar rha h

    for(int i = 0; i<edges.size(); i++) {

        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    vector<int> indegree(n);    // isse kitne log point kar rhe h
    for(auto i:adj) {

        for(auto j:i.second) {

            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<n; i++) {

        if(indegree[i] == 0)
        q.push(i);
    }

    int count = 0;
    while(!q.empty()) {

        int front = q.front();
        q.pop();

        count++;
        
        for(auto neigh:adj[front]) {

            indegree[neigh]--;
            if(indegree[neigh] == 0)
            q.push(neigh);
        }
    }

    if(count == n) 
    return 0;

    else 
    return 1;
}