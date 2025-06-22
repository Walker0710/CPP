#include <bits/stdc++.h>

using namespace std;

// << ,

int minTimeToReach(vector<vector<int>> &moveTime)
{
    int n = moveTime.size();
    int m = moveTime[0].size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minH;
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    minH.push({0, 0, 0});
    moveTime[0][0] = 0;

    vector<vector<int>> dirc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!minH.empty())
    {
        vector<int> yoo = minH.top();
        minH.pop();

        int t = yoo[0];
        int r = yoo[1];
        int c = yoo[2];

        if (t >= dp[r][c])
            continue;

        if (r == n - 1 && c == m - 1)
            return t;

        dp[r][c] = t;

        for (auto &d : dirc)
        {
            int row = r + d[0];
            int col = c + d[1];

            if (row >= 0 && row < n && col >= 0 && col < m && dp[row][col] == INT_MAX)
            {
                int exTime = max(moveTime[row][col], t) + 1;
                minH.push({exTime, row, col});
            }
        }
    }
    return -1;
}