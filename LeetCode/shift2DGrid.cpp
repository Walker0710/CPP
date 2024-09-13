#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{

    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> yo(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {

            yo[i][j] = grid[i][j];
        }
    }

    while (k--)
    {

        for (int i = 0; i <= col - 2; i++)
        {

            for (int j = 0; j < row; j++)
            {

                yo[j][i] = grid[j][i + 1];
            }
        }

        for (int i = 0; i < row; i++)
        {

            yo[i][col - 1] = grid[i][0];
        }

        
    }

    return yo;
}