#include <bits/stdc++.h>

using namespace std;

// << ,

int bfs(vector<vector<int>> &grid, int i, int j)
{
    queue<pair<int, int>> q;
    int ans = 0;
    vector<pair<int, int>> diresction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));

    visit[i][j] = true;
    q.push({i, j});

    while (!q.empty())
    {
        int len = q.size();

        for (int k = 0; k < len; k++)
        {
            pair<int, int> top = q.front();
            q.pop();

            if (grid[top.first][top.second] == 0)
                return ans;

            for (auto dir : diresction)
            {
                int row = top.first + dir.first;
                int col = top.second + dir.second;

                if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] != -1 && !visit[row][col])
                {
                    visit[row][col] = true;
                    q.push({row, col});
                }
            }
        }

        ans++;
    }

    return -1;
}

void islandsAndTreasure(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {

            if (grid[i][j] == INT_MAX)
            {
                grid[i][j] = bfs(grid, i, j);
            }
        }
    }
}