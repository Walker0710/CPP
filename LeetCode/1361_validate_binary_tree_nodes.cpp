#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <set>

using namespace std;

void dfs(int node, unordered_map<int, bool> &visi, unordered_map<int, list<int>> &adj) {

    visi[node] = true;

    for(auto i:adj[node]) {

        if(!visi[i]) {

            dfs(i, visi, adj);
        }
    }
}

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    unordered_map<int, list<int>> adj;
    vector<int> indegree(n);

    for(int i = 0; i<n; i++) {
        if(leftChild[i] != -1)  {
            adj[i].push_back(leftChild[i]);
            indegree[leftChild[i]]++;
        }

        if(rightChild[i] != -1) {
            adj[i].push_back(rightChild[i]);
            indegree[rightChild[i]]++;
        }
    }

    int zeroindegree = 0;
    bool oneindegree = true;
    int index = 0;

    for(int i = 0; i<n; i++) {
        if(indegree[i] == 0) {
            zeroindegree++;
            index = i;
        } 

        if(indegree[i] > 1) {
            oneindegree = false;
            break;
        }
    }

    if(!oneindegree || zeroindegree != 1) {
        return false;
    }

    unordered_map<int, bool> visi;
    dfs(index, visi, adj);

    bool connected = true;

    for(int i = 0; i<n; i++) {
        if(visi[i] == false) {
            connected = false;
            break;
        }
    }

    bool ans = (connected);
    return ans;
}