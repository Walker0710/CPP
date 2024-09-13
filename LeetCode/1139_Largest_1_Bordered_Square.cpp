#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int largest1BorderedSquare(vector<vector<int>> &grid)
{
    int side = 0;
    vector<vector<int>> row = grid, col = grid;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            // compute row-wise and col-wise prefix sum
            if (grid[i][j] == 1)
            {
                row[i][j] = (j > 0) ? 1 + row[i][j - 1] : 1;
                col[i][j] = (i > 0) ? 1 + col[i - 1][j] : 1;
            }
            else
            { // if value in grid is 0, then its value in both row and col will be 0
                row[i][j] = 0;
                col[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            int limit = min(row[i][j], col[i][j]);
            // check for all possibilities of making a square
            for (int mini = 1; mini <= limit; mini++)
            {
                if (i - (mini - 1) >= 0 && j - (mini - 1) >= 0 && row[i - (mini - 1)][j] >= mini && col[i][j - (mini - 1)] >= mini)
                {
                    side = max(side, mini); // update maximum possible side
                }
            }
        }
    }
    return side * side; // return it's area
}