#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <unordered_map>

using namespace std;

//only rec
int solve(int n) {

    if(n == 1 || n == 0) 
    return 1;

    int ans = 0;

    for(int root = 1; root<=n; root++) 
    ans += solve(root-1)*solve(n - root);

    return ans;
}

int numTrees(int n) {

    return solve(n);
}

//rec + mem
int solveMem(int n, vector<int> &dp) {

    if(n == 1 || n == 0) 
    return 1;

    if(dp[n] == -1)
    return dp[n];

    int ans = 0;

    for(int root = 1; root<=n; root++) 
    ans += solve(root-1)*solve(n - root);

    dp[n] = ans;

    return dp[n];
}

int numTrees(int n) {

    vector<int> dp;
    return solveMem(n, dp);
}

//tabulation
int solveTab(int n) {

    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    int ans = 0;

    for(int i = 2; i<=n; i++) {

        for(int root = 1; root<=i; root++) {

            dp[i] += dp[root - 1]*dp[i-root];
        }
    } 
    return dp[n];
}

int numTrees(int n) {

    return solveTab(n);
}

