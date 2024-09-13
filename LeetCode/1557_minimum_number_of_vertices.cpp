#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> indegree(n);

    for(int i = 0; i<edges.size(); i++) {
        indegree[edges[i][1]]++;
    }

    vector<int> ans;
    for(int i = 0; i<n; i++) {
        if(indegree[i] == 0) {
            ans.push_back(i);
        } 
    }

    return ans;
}