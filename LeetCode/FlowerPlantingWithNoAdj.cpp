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

void dfs(int node, int color, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int n)
{
    visited[node] = true;
    ans.push_back(color);

    for (auto neigh : adj[node])
    {
        if (!visited[neigh]) 
        {
            dfs(neigh, (color + 1), adj, visited, ans, n);
        }
    }
}

vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
{
    vector<int> ans;
    if(paths.size() == 0) {

        for(int i = 0; i<paths.size(); i++) {

            ans.push_back(1);
        }
        return ans;
    }

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < paths.size(); i++)
    {
        adj[paths[i][0]].push_back(paths[i][1]);
        adj[paths[i][1]].push_back(paths[i][0]);
    }

    unordered_map<int, bool> visited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int color = 1;
            dfs(i, color, adj, visited, ans, n);
        }
    }
    return ans;
}

//2nd 
void bfs(int node, vector<int> &colorVec, int color, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited) {

    queue<int> q;
    q.push(node);
    visited[node] = true;
    colorVec[node] = color++;

    while(!q.empty()) {

        int frontNode = q.front();
        q.pop();

        for(auto i:adj[frontNode]) {

            if(visited[i] && colorVec[i] == colorVec[frontNode]) {

                colorVec[i]++;

                if(colorVec[i] > 4)
                colorVec[i] = 1;
            }

            if(!visited[i]) {

                q.push(i);
                colorVec[i] = color++;
                
                if(color > 4) 
                color = 1;

                visited[i] = true;
            }
        }
    }
}

vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {

    vector<int> colorVec(n+1);

    unordered_map<int, list<int>> adj;
    
    for(int i = 0; i<=paths.size(); i++) {

        adj[paths[i][0]].push_back(paths[i][1]);
        adj[paths[i][1]].push_back(paths[i][0]);
    }

    unordered_map<int, bool> visited(n+1);

    for(int i = 1; i<=n; i++) {

        if(!visited[i]) {

            int color = 1;
            bfs(i, colorVec, color, adj, visited);
        }
    }

    vector<int> ans;
    copy(colorVec.begin() + 1, colorVec.end(), back_inserter(ans));

    return ans;
}

