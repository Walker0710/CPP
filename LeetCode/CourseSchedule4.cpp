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

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    unordered_map<int, list<int>> adj;

    for(int i = 0; i<prerequisites.size(); i++) {

        int u = prerequisites[i][0];
        int v = prerequisites[i][1];

        adj[u].push_back(v);
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

int binarySearch(vector<int> &TopoSort, int target) {

    int s = 0;
    int e = TopoSort.size() - 1;

    while(s<=e) {

        int mid = (s+e)/2;

        if(TopoSort[mid] == target) 
        return mid;

        else if(TopoSort[mid] < target) 
        s = mid+1;

        else 
        e = mid - 1;
    }
    return -1;
} 

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

    vector<int> TopoSort = findOrder(numCourses, prerequisites);
    int noOfQueries = queries.size();
    vector<bool> ans;

    for(int i = 0; i<noOfQueries; i++) {

        int p = binarySearch(TopoSort, queries[i][0]);
        int q = binarySearch(TopoSort, queries[i][1]);

        if(p < q) 
        ans.push_back(true);

        else 
        ans.push_back(false);
    }
    return ans;
}

//2nd approch
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {}
