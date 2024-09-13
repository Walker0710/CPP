#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

//only rec
int solve(vector<int>& values, int i, int j) {

    if(i+1 == j) 
    return 0;

    int mini = INT_MAX;

    for(int k = i+1; k<j; k++) {

        int ans = values[i]*values[j]*values[k] + solve(values, i, k) + solve(values, k, j);
        mini = min(mini, ans);
    }
    return mini;    
}

int minScoreTriangulation(vector<int>& values) {

    int n = values.size();
    return solve(values, 0, n-1);
}

//rec + Mem
int solveMem(vector<int>& values, int i, int j, vector<vector<int>> &dp) {

    if(i+1 == j)
    return 0;

    if(dp[i][j] != -1)
    return dp[i][j];

    int mini = INT_MAX;

    for(int k = i+1; k<j; k++) {

        int ans = values[i]*values[j]*values[k] + solveMem(values, i, k, dp) + solveMem(values, k, j, dp);
        mini = min(mini, ans);
    }

    dp[i][j] = mini;
    return dp[i][j];   
}

int minScoreTriangulation(vector<int>& values) {

    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveMem(values, 0, n-1, dp);
}

//Tabulation
int solveTab(vector<int>& values, int &mini) {

    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0)); 

    for(int i = n-1; i>=0; i--) {

        for(int j = i+2; j<n; j++) {

            int mini = INT_MAX;

            for(int k = i + 1; k<j; k++) {

                int ans = values[i]*values[j]*values[k] + dp[i][k] + dp[k][j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }

    return dp[0][n-1];
}

int minScoreTriangulation(vector<int>& values) {

    int mini = 0;
    return solveTab(values, mini);
}