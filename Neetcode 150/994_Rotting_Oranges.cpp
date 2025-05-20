#include <bits/stdc++.h>

using namespace std;

// << ,

int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (grid[i][j] == 2)
            q.push({i, j});
            
            else if (grid[i][j] == 1)
            fresh++;
        }
    }

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minutes = 0;

    while (!q.empty() && fresh > 0) {
    
        int len = q.size();
    
        for (int i = 0; i < len; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (auto &[dx, dy] : directions) {
    
                int row = x + dx;
                int col = y + dy;

                if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1) {
    
                    grid[row][col] = 2;
                    q.push({row, col});
                    fresh--;
                }
            }
        }
        minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}