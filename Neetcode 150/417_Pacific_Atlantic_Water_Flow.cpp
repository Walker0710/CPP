#include <bits/stdc++.h>

using namespace std;

// << ,

void dfs(vector<vector<int>> &heights, int i, int j, bool &pacific, bool &atlantic)
{
    if (i <= 0 || j <= 0)
    {
        pacific = true;
        return;
    }

    if (i >= heights.size() - 1 || j >= heights[0].size() - 1)
    {
        atlantic = true;
        return;
    }

    vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (auto &[dx, dy] : direction)
    {
        int row = i + dx;
        int col = j + dy;

        if (heights[i][j] >= heights[row][col])
        {
            dfs(heights, row, col, pacific, atlantic);

            if (pacific && atlantic)
                break;
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<int>> ans;

    for (int i = 0; i < heights.size(); i++)
    {
        for (int j = 0; j < heights[0].size(); j++)
        {
            bool pacific = false;
            bool atlantic = false;

            dfs(heights, i, j, pacific, atlantic);

            if (pacific && atlantic)
            {
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}

// 2nd approch

int ROWS, COLS;
bool pacific, atlantic;
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<int>> &heights, int r, int c, int prevVal)
{
    if (r < 0 || c < 0)
    {
        pacific = true;
        return;
    }

    if (r >= ROWS || c >= COLS)
    {
        atlantic = true;
        return;
    }

    if (heights[r][c] > prevVal)
    {
        return;
    }

    int tmp = heights[r][c];
    heights[r][c] = INT_MAX;

    for (auto &dir : directions)
    {
        dfs(heights, r + dir[0], c + dir[1], tmp);

        if (pacific && atlantic)
        {
            break;
        }
    }

    heights[r][c] = tmp;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    ROWS = heights.size();
    COLS = heights[0].size();
    vector<vector<int>> res;

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            pacific = false;
            atlantic = false;

            dfs(heights, r, c, INT_MAX);

            if (pacific && atlantic)
            {
                res.push_back({r, c});
            }
        }
    }

    return res;
}

// 3rd approch

vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int ROWS = heights.size(), COLS = heights[0].size();
    vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
    vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

    for (int c = 0; c < COLS; ++c)
    {
        dfs(0, c, pac, heights);
        dfs(ROWS - 1, c, atl, heights);
    }
 
    for (int r = 0; r < ROWS; ++r)
    {
        dfs(r, 0, pac, heights);
        dfs(r, COLS - 1, atl, heights);
    }

    vector<vector<int>> res;
 
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            if (pac[r][c] && atl[r][c])
            {
                res.push_back({r, c});
            }
        }
    }
    return res;
}

void dfs(int r, int c, vector<vector<bool>> &ocean, vector<vector<int>> &heights)
{
    ocean[r][c] = true;
 
    for (auto [dr, dc] : directions)
    {
        int nr = r + dr, nc = c + dc;
        if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
        {
            dfs(nr, nc, ocean, heights);
        }
    }
}