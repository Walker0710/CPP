#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>

using namespace std;

//1st
void makeSet(vector<int> &parent, vector<int> &rank, int n) {             

    for(int i = 0; i<n; i++) {

        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {  
                                                        
    if(parent[node] == node)
    return node;

    return findParent(parent, parent[node]);
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

bool canVisitAllRooms(vector<vector<int>>& rooms) {
 
    int n = rooms.size();
    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);

    for(int i = 0; i < n; i++) {

        for(auto j:rooms[i]) {

            int u = findParent(parent, i);
            int v = findParent(parent, j);

            if(u != v) {

                unionSet(u, v, parent, rank);
            }
        }
    }

    set<int> yo;

    for(int i = 0; i<n; i++) {

        int yo1 = findParent(parent, i);
        yo.insert(yo1);
    }

    if(yo.size() == 1) 
    return true;

    return false;
}

//2nd 
bool canVisitAllRooms(vector<vector<int>>& rooms) {

    queue<int> q;
    unordered_map<int, bool> visited;
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {

        int front = q.front();
        q.pop();

        for(auto i:rooms[front]) {

            if(!visited[i]) {

                q.push(i);
                visited[i] = true;
            }
        }
    }

    for(int i = 0; i<rooms.size(); i++) {

        if(!visited[i]) 
        return false;
    }

    return true;
}