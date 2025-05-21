#include <bits/stdc++.h>

using namespace std;

// << ,

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adj;
    vector<int> inDegree(numCourses);

    for(int i = 0; i<prerequisites.size(); i++) {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];

        adj[v].push_back(u);
        inDegree[u]++;
    }

    queue<int> q;

    for(int i = 0; i<numCourses; i++) {
        if(inDegree[j] == 0)
        q.push(i);
    }

    int count = 0;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        count++;

        for(auto neigh:adj[front]) {
            inDegree[neigh]--;

            if(inDegree[neigh] == 0) 
            q.push(neigh);
        }
    }

    if(count == numCourses) 
    return true;

    return false;
}