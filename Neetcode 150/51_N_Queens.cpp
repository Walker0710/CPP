#include <bits/stdc++.h>

using namespace std;

// << ,

bool isSafe(int row, int col, vector<string> &board, int n)
{
    // Check same column on left side
    for (int y = 0; y < col; y++)
    {
        if (board[row][y] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
    {
        if (board[x][y] == 'Q')
            return false;
    }

    // Check lower-left diagonal
    for (int x = row, y = col; x < n && y >= 0; x++, y--)
    {
        if (board[x][y] == 'Q')
            return false;
    }

    return true;
}

void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, ans, board, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, ans, board, n);
    return ans;
}