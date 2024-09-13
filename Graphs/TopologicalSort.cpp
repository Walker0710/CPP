#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>

using namespace std;

//only for directed acyclic graph
// 1st using DFS

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {

    visited[node] = 1;

    for(auto neigh:adj[node]) {

        if(!visited[neigh]) 
        topoSort(neigh, visited, s, adj);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {

    unordered_map<int, list<int>> adj;

    for(int i = 0; i<edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i = 0; i<v; i++) {

        if(!visited[i])
        topoSort(i, visited, s, adj);
    }

    vector<int> ans;

    while(!s.empty()) {

        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// upar wle soln me TL aa rha h unordered map use karne ke wajh se
void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {

    visited[node] = 1;

    for(auto neigh:adj[node]) {

        if(!visited[neigh]) 
        topoSort(neigh, visited, s, adj);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {

    unordered_map<int, list<int>> adj;

    for(int i = 0; i<edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;

    for(int i = 0; i<v; i++) {

        if(!visited[i])
        topoSort(i, visited, s, adj);
    }

    vector<int> ans;

    while(!s.empty()) {

        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}


//2nd using BFS - Kahn's algo
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {

    unordered_map<int, list<int>> adj;  //kitno ko ye point kar rha h

    for(int i = 0; i<edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(v);    // isse kitne log point kar rhe h
    for(auto i:adj) {

        for(auto j:i.second) {

            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<v; i++) {

        if(indegree[i] == 0)
        q.push(i);
    }

    vector<int> ans;
    while(!q.empty()) {

        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neigh:adj[front]) {

            indegree[neigh]--;
            if(indegree[neigh] == 0)
            q.push(neigh);
        }
    }

    return ans;
}