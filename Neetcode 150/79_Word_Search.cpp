#include <bits/stdc++.h>

using namespace std;

// << ,

bool solve(int index, int i, int j, int n, int m, vector<vector<char>> &board, string &word)
{
    if (index == word.length())
    {
        return true;
    }

    if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index] || board[i][j] == '#')
    {
        return false;
    }

    board[i][j] = '#';

    bool res = solve(index + 1, i + 1, j, n, m, board, word) || solve(index + 1, i - 1, j, n, m, board, word) || solve(index + 1, i, j + 1, n, m, board, word) || solve(index + 1, i, j - 1, n, m, board, word);
    board[i][j] = word[index];
 
    return res;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool ans = solve(0, i, j, n, m, board, word);

            if (ans)
                return true;
        }
    }

    return false;
}