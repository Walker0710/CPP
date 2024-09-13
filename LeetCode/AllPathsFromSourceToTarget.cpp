#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>

using namespace std;

void dfs(int node, int target, vector<vector<int>> &graph, vector<int> &toPush, vector<vector<int>> &ans)
{
    toPush.push_back(node);

    if (node == target)
    {
        ans.push_back(toPush);
    }

    else
    {
        for (auto i : graph[node])
        {
            dfs(i, target, graph, toPush, ans);
        }
    }
    toPush.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{

    int n = graph.size();
    vector<int> toPush;
    vector<vector<int>> ans;

    dfs(0, n - 1, graph, toPush, ans);

    return ans;
}

// 2nd using BFS
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> ans;
    queue<pair<int, vector<int>>> q;
    q.push({0, {0}});
    while (q.size())
    {
        int f = q.front().first;
        vector<int> vec = q.front().second;
        q.pop();
        for (auto v : graph[f])
        {
            vec.push_back(v);
            if (v == graph.size() - 1)
            {
                ans.push_back(vec);
            }
            else
            {
                q.push({v, vec});
            }
            vec.pop_back();
        }
    }
    return ans;
}
