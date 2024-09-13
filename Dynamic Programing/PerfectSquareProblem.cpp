#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

//only Rec
int solve(int n) {

    if(n == 0)
    return 0;

    int ans = n;

    for(int i = 1; i*i<= n; i++) 
    ans = min(ans, 1+solve(n - i*i));

    return ans;
}

int MinSquares(int n) {

    return solve(n);
}

//Rec + Memo
int solveMem(int n, vector<int> &dp) {

    if(n == 0)
    return 0;

    if(dp[n] != -1)
    return dp[n];

    int ans = n;

    for(int i = 1; i*i<=n; i++) 
    ans = min(ans, 1+solveMem(n-i*i, dp));

    dp[n] = ans;
    return dp[n];
}

int MinSquares(int n) {
    
    vector<int> dp(n+1, -1);
    return solveMem(n, dp);
}

//Tabulation 
int MinSquares(int n) {

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i<=n;  i++) {

        for(int j = 1; j*j <= 1; j++) {

            dp[i] = min(dp[i],1 + dp[i- j*j]);
        }
    }
    return dp[n];
}

