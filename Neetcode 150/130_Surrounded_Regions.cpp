#include <bits/stdc++.h>

using namespace std;

// << ,
void dfs(vector<vector<char>> &board, int r, int c)
{
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == 'X')
        return;

    board[r][c] = 'T';

    vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (auto &[dx, dy] : direction)
    {
        int row = r + dx;
        int col = c + dy;

        if (row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && board[row][col] == 'O')
        {
            dfs(board, row, col);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    if (board.empty())
        return;

    int n = board.size();
    int m = board[0].size();

    vector<pair<int, int>> rec;

    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O')
            rec.push_back({0, i});
        if (board[n - 1][i] == 'O')
            rec.push_back({n - 1, i});
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
            rec.push_back({i, 0});
        if (board[i][m - 1] == 'O')
            rec.push_back({i, m - 1});
    }

    for (auto &[r, c] : rec)
    {
        dfs(board, r, c);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
            else if (board[i][j] == 'T')
            {
                board[i][j] = 'O';
            }
        }
    }
}