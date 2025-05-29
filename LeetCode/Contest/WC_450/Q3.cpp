#include <bits/stdc++.h>

using namespace std;

// << ,



// DFS

vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solve(vector<string> &matrix, int i, int j, int n, int m,
          unordered_map<char, vector<pair<int, int>>> &rec,
          vector<vector<bool>> &visited,
          unordered_set<char> usedPortals,
          vector<vector<int>> &dp)
{

    if (i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] == '#' || visited[i][j])
    {
        return INT_MAX - 10;
    }

    if (i == n - 1 && j == m - 1)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    visited[i][j] = true;
    int ans = INT_MAX;

    // Try moving to adjacent cells
    for (auto &[dx, dy] : directions)
    {
        int row = i + dx;
        int col = j + dy;
        ans = min(ans, 1 + solve(matrix, row, col, n, m, rec, visited, usedPortals, dp));
    }

    if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z')
    {
        char portal = matrix[i][j];
        if (usedPortals.find(portal) == usedPortals.end())
        {
            usedPortals.insert(portal);
            for (auto &[dx, dy] : rec[portal])
            {
                if (dx == i && dy == j)
                    continue;
                ans = min(ans, solve(matrix, dx, dy, n, m, rec, visited, usedPortals, dp));
            }
        }
    }

    visited[i][j] = false;
    return dp[i][j] = ans;
}

int minMoves(vector<string> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    unordered_map<char, vector<pair<int, int>>> rec;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z')
            {
                rec[matrix[i][j]].push_back({i, j});
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    unordered_set<char> usedPortals; // initially empty

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int res = solve(matrix, 0, 0, n, m, rec, visited, usedPortals, dp);
    return (res >= INT_MAX - 10) ? -1 : res;
}




// BFS

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int m, n;

bool isvalid(int x, int y) { return x >= 0 && y >= 0 && x < m && y < n; }

int minMoves(vector<string> &matrix)
{
    m = matrix.size(), n = matrix[0].size();

    if (matrix[m - 1][n - 1] == '#')
    return -1;

    vector<vector<pair<int, int>>> portals(26);
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (isalpha(matrix[i][j]))
                portals[matrix[i][j] - 'A'].emplace_back(i, j);
        }
    }

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<bool> used(26, false);
    deque<vector<int>> dq;
    dq.push_front({0, 0, 0}); // {moves, x, y}

    while (!dq.empty())
    {
        vector<int> curr = dq.front();
        dq.pop_front();
        int moves = curr[0], i = curr[1], j = curr[2];

        if (i == m - 1 && j == n - 1)
            return moves;

        if (vis[i][j])
            continue;

        vis[i][j] = true;

        // Use portal if not used
        if (isalpha(matrix[i][j]))
        {
            int portalID = matrix[i][j] - 'A';
            if (!used[portalID])
            {
                used[portalID] = true;
                for (auto &[x, y] : portals[portalID])
                {
                    if (!vis[x][y])
                    {
                        dq.push_front({moves, x, y}); // portal cost = 0
                    }
                }
            }
        }

        // Normal moves (cost = 1)
        for (int k = 0; k < 4; ++k)
        {
            int x = i + dx[k], y = j + dy[k];
            if (isvalid(x, y) && !vis[x][y] && matrix[x][y] != '#')
            {
                dq.push_back({moves + 1, x, y});
            }
        }
    }

    return -1;
}