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

int bfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visi) {
    int count = 0;
    queue<int> q;
    q.push(node);
    visi[node] = true;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        count++;

        for(auto neigh : adj[front]) {
            if(!visi[neigh]) {
                q.push(neigh);
                visi[neigh] = true;
            }
        }
    }
    return count;
}

int maximumDetonation(vector<vector<int>>& bombs) {
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < bombs.size(); i++) {
        for(int j = 0; j < bombs.size(); j++) {
            if (i != j) {
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long distanceSquared = dx * dx + dy * dy;
                long long radiusSquared = (long long)bombs[i][2] * bombs[i][2];

                if (distanceSquared <= radiusSquared) {
                    adj[i].push_back(j);
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < bombs.size(); i++) {
        vector<bool> visi(bombs.size(), false);  
        ans = max(ans, bfs(i, adj, visi));
    }

    return ans;
}