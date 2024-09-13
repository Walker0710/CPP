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

int bfs(vector<vector<int>> &stones, int start_index, vector<bool> &visited, int n)
{
    queue<int> q;
    q.push(start_index);
    visited[start_index] = true;
    int count = 0;
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if ((stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
                {
                    visited[i] = true;
                    q.push(i);
                    count++;
                }
            }
        }
    }
    return count;
}

int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    vector<bool> visited(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans += bfs(stones, i, visited, n);
        }
    }
    return ans;
}

// 2nd approch
int dfs(vector<vector<int>> &stones, int index, vector<bool> &visited, int n)
{
    visited[index] = true;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (((stones[i][0] == stones[index][0] or stones[i][1] == stones[index][1])))
            {
                result += dfs(stones, i, visited, n) + 1;
            }
        }
    }
    return result;
}

int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    vector<bool> visited(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans += dfs(stones, i, visited, n);
        }
    }
    return ans;
}
