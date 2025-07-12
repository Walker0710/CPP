#include <bits/stdc++.h>

using namespace std;

// << ,

bool canMakeSquare(vector<vector<char>> &grid)
{
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0;

    if (grid[0][0] == 'B')
    {
        first++;
    }

    if (grid[0][1] == 'B')
    {
        first++;
        second++;
    }

    if (grid[0][2] == 'B')
    {
        second++;
    }

    if (grid[1][0] == 'B')
    {
        first++;
        third++;
    }

    if (grid[1][1] == 'B')
    {
        first++;
        second++;
        third++;
        fourth++;
    }

    if (grid[1][2] == 'B')
    {
        second++;
        fourth++;
    }

    if (grid[2][0] == 'B')
    {
        third++;
    }

    if (grid[2][1] == 'B')
    {
        third++;
        fourth++;
    }

    if (grid[2][2] == 'B')
    {
        fourth++;
    }

    if (first <= 1 || first >= 3)
        return true;

    if (second <= 1 || second >= 3)
        return true;

    if (third <= 1 || third >= 3)
        return true;

    if (fourth <= 1 || fourth >= 3)
        return true;


    return false;
}