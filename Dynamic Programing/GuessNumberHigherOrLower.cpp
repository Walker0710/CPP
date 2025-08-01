#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <unordered_map>

using namespace std;

//only rec
int solve(int start, int end) {

    if(start >= end) 
    return 0;

    int ans = INT_MAX;

    for(int i = start; i<=end; i++) {

        ans = min(ans, i+max(solve(start, i - 1), solve(i + 1, end)));
    }
    return ans;
}

int getMoneyAmount(int n) {

    return solve(1, n);
}

//rec + mem
int solveMem(int start, int end, vector<vector<int>> &dp) {

    if(start >= end) 
    return 0;

    if(dp[start][end] != -1) 
    return dp[start][end];

    int ans = INT_MAX;

    for(int i = start; i<=end; i++) {

        ans = min(ans, i+max(solveMem(start, i - 1, dp), solveMem(i + 1, end, dp)));
    }

    dp[start][end] = ans;
    return dp[start][end];
}

int getMoneyAmount(int n) {

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solveMem(1, n, dp);
}

//tabulation
int solveTab(int n) {

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int start = n; start >= 1; start--) {

        for(int end = start; end <= n; end++) {

            if(end == start)
            continue;
            
            int ans = INT_MAX;

            for(int i = start; i<=end; i++) {

                ans = min(ans, i+max(dp[start][i-1], dp[i+1][end]));
            }

            dp[start][end] = ans;
        }
    }
    return dp[1][n];
}

int getMoneyAmount(int n) {

    return solveTab(n);
}

