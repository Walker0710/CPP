#include <bits/stdc++.h>

using namespace std;

// << ,

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool searchInDirection(vector<vector<char>> &grid, int x, int y, string &word, int dirX, int dirY)
{
    int n = grid.size(), m = grid[0].size();
    int len = word.size();

    for (int i = 0; i < len; i++)
    {
        int newX = x + i * dirX;
        int newY = y + i * dirY;

        if (newX < 0 || newX >= n || newY < 0 || newY >= m || grid[newX][newY] != word[i])
        {
            return false;
        }
    }

    return true;
}

vector<vector<int>> searchWord(vector<vector<char>> &grid, string word)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == word[0])
            { 
                for (int d = 0; d < 8; d++)
                { 
                    if (searchInDirection(grid, i, j, word, dx[d], dy[d]))
                    {
                        result.push_back({i, j}); 
                        break; 
                    }
                }
            }
        }
    }

    sort(result.begin(), result.end()); 
    return result;
}

