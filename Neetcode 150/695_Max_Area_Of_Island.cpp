#include <bits/stdc++.h>

using namespace std;

// << ,

int dfs(vector<vector<int>> &grid, int i, int j) {
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
        return 0;
    }

    int cnt = 1;

    grid[i][j] = 0;

    cnt += dfs(grid, i, j+1);
    cnt += dfs(grid, i, j-1);
    cnt += dfs(grid, i+1, j);
    cnt += dfs(grid, i-1, j);

    return cnt;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {

            if(grid[i][j] == 1) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
    }

    return ans;
}

//2nd approch

void dfs(vector<vector<int>> &grid, int i, int j, int &cnt) {
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
        return ;
    }

    cnt++;

    grid[i][j] = 0;

    dfs(grid, i, j+1, cnt);
    dfs(grid, i, j-1, cnt);
    dfs(grid, i+1, j, cnt);
    dfs(grid, i-1, j, cnt);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {

            if(grid[i][j] == 1) {
                int cnt = 0;
                dfs(grid, i, j, cnt);

                ans = max(ans, cnt);
            }
        }
    }

    return ans;
}