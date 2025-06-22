#include <bits/stdc++.h>

using namespace std;

// << ,

int dp1[1001][1001];
int dp2[1001][1001];
int n;

int solve(int x, int y, vector<vector<int>> &arr)
{
    if (x == n - 2 && y == n - 1)
    return arr[x][y];
    
    if (dp1[x][y] != -1)
    return dp1[x][y];

    int ans = arr[x][y];
    int take1 = 0, take2 = 0, take3 = 0;

    if (x + 1 < n && y + 1 < n && x + 1 < y + 1)
    {
        take1 = solve(x + 1, y + 1, arr);
    }

    if (x + 1 < n && x + 1 < y)
    {
        take2 = solve(x + 1, y, arr);
    }

    if (x + 1 < n && y - 1 >= 0 && x + 1 < y - 1)
    {
        take3 = solve(x + 1, y - 1, arr);
    }

    ans += max({take1, take2, take3});

    return dp1[x][y] = ans;
}

int solve2(int x, int y, vector<vector<int>> &arr)
{
    if (x == n - 2 && y == n - 1)
    return arr[x][y];

    if (dp2[x][y] != -1)
    return dp2[x][y];
    
    int ans = arr[x][y];
    int take1 = 0, take2 = 0, take3 = 0;
    
    if (x + 1 < n && y + 1 < n && x + 1 > y + 1)
    {
        take1 = solve2(x + 1, y + 1, arr);
    }
    
    if (y + 1 < n && x > y + 1)
    {
        take2 = solve2(x, y + 1, arr);
    }
    
    if (x - 1 >= 0 && y + 1 < n && x - 1 > y + 1)
    {
        take3 = solve2(x - 1, y + 1, arr);
    }
    
    ans += max({take1, take2, take3});
    return dp2[x][y] = ans;
}

int maxCollectedFruits(vector<vector<int>> &fruits)
{
    n = fruits.size();
    
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    int ans1 = solve(0, n - 1, fruits);
    int ans2 = solve2(n - 1, 0, fruits);
    int ans3 = 0;
    
    for (int i = 0; i < n; i++)
        ans3 += fruits[i][i];
    
    return ans1 + ans2 + ans3;
}