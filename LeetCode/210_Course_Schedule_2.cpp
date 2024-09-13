#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<limits.h>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    unordered_map<int, list<int>> adj;

    for(int i = 0; i<prerequisites.size(); i++) {

        int u = prerequisites[i][0];
        int v = prerequisites[i][1];

        adj[v].push_back(u);
    }

    vector<int> inDegree(numCourses);

    for(auto i:adj) {

        for(auto j:i.second) {

            inDegree[j]++;
        }
    }

    queue<int> q;
    
    for(int i = 0; i< numCourses; i++) {

        if(inDegree[i] == 0) 
        q.push(i);
    }

    vector<int> ans;

    while(!q.empty()) {

        int front = q.front();
        q.pop();
        
        ans.push_back(front);

        for(auto neigh:adj[front]) {

            inDegree[neigh]--;
            if(inDegree[neigh] == 0)
            q.push(neigh);
        }
    }

    if(ans.size() == numCourses)
    return ans;

    return {};
}