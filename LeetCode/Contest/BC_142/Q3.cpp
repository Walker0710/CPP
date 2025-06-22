#include <bits/stdc++.h>

using namespace std;

// << ,

vector<vector<int>> dp;

int solve(int n, int k, int day, int curCity, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore)
{
    if (day >= k)
        return 0;
 
    if (dp[day][curCity] != -1)
        return dp[day][curCity];

    int res = stayScore[day][curCity] + solve(n, k, day + 1, curCity, stayScore, travelScore);

    for (int nextCity = 0; nextCity < n; ++nextCity)
    {
        if (nextCity == curCity)
            continue;

        res = max(res, travelScore[curCity][nextCity] + solve(n, k, day + 1, nextCity, stayScore, travelScore));
    }

    return dp[day][curCity] = res;
}

int maxScore(int n, int k, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore)
{
    dp.resize(k + 1, vector<int>(n + 1, -1));
    int ans = 0;
    
    for (int startCity = 0; startCity < n; ++startCity)
        ans = max(ans, solve(n, k, 0, startCity, stayScore, travelScore));
    
    return ans;
}