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

vector<int> topologicalSort(int numCourses, vector<vector<int>> &prerequisites)
{

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < prerequisites.size(); i++)
    {

        int u = prerequisites[i][0];
        int v = prerequisites[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(numCourses);
    for (auto i : adj)
    {

        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {

        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {

        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neigh : adj[front])
        {

            indegree[neigh]--;
            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    return ans;
}

bool solve(vector<int> &topo, vector<int> &pair)
{
    int first = pair[0];
    int second = pair[1];

    int firstIt = 0;
    int secondIt = 0;

    for (int i = 0; i < topo.size(); i++)
    {
        if (topo[i] == first)
            firstIt = i;

        if (topo[i] == second)
            secondIt = i;
    }

    return firstIt < secondIt;
}

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
{
    vector<bool> ans(queries.size());

    if (prerequisites.size() == 0)
    {
        return ans;
    }

    vector<int> topo = topologicalSort(numCourses, prerequisites);

    for (int i = 0; i < queries.size(); i++)
    {
        ans[i] = solve(topo, queries[i]);
    }

    return ans;
}

// 2nd approch
vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
{
    vector<bool> ans;
    vector<vector<int>> graph(n);
    vector<vector<bool>> table(n, vector<bool>(n, false));
    vector<int> indegree(n, 0);

    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        indegree[prerequisites[i][1]]++;
    }

    queue<int> q;
    
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
        q.push(i);
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto &it : graph[cur])
        {
            table[cur][it] = true;

            for (int i = 0; i < n; i++)
                if (table[i][cur] == true)
                table[i][it] = true;

            indegree[it]--;

            if (indegree[it] == 0)
            q.push(it);
        }
    }
    
    for (int i = 0; i < queries.size(); i++)
    ans.push_back(table[queries[i][0]][queries[i][1]]);

    return ans;
}