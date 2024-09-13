#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

//only rec
bool solve(int index, int arr[], int N, int target) {

    if(index >= N)
    return 0;

    if(target < 0)
    return 0;

    if(target == 0)
    return 1;

    bool incl = solve(index+1, arr, N, target - arr[index]);
    bool excl = solve(index+1, arr, N, target - 0);

    return incl or excl;
}

int equalPartition(int N, int arr[]) {

    int total = 0;

    for(int i = 0; i<N; i++) 
    total = total + arr[i];

    if(total & 1)
    return 0;
    
    return solve(0, arr, N, total/2);
}

//rec + mem
bool solveMem(int index, int arr[], int N, int target, vector<vector<int>> &dp) {

    if(index >= N)
    return 0;

    if(target < 0)
    return 0;

    if(target == 0)
    return 1;

    if(dp[index][target] != -1)
    return dp[index][target];

    bool incl = solveMem(index+1, arr, N, target - arr[index], dp);
    bool excl = solveMem(index+1, arr, N, target - 0, dp);

    return dp[index][target] = incl or excl;
}

int equalPartition(int N, int arr[]) {

    int total = 0; 

    for(int i = 0; i<N; i++) 
    total = total + arr[i];

    if(total & 1)
    return 0;

    vector<vector<int>> dp(N+1, vector<int>(total/2 + 1, -1));
    return solveMem(0, arr, N, total/2, dp);
}

//tabulation
int solveTab(int arr[], int N, int t) {

    vector<vector<int>> dp(N+1, vector<int>(t + 1, 0));

    for(int i = 0; i<=N; i++) 
    dp[i][0] = 1;

    for(int index = N-1; index >= 0; index--) {

        for(int target = 0; target <= t; target++) {

            bool incl;
            if(target - arr[index] >= 0)
            incl = dp[index+1][target - arr[index]];
            bool excl = dp[index+1][target - 0];

            dp[index][target] = incl or excl;
        }
    }

    return dp[0][t];
}

int equalPartition(int N, int arr[]) {

    int total = 0; 

    for(int i = 0; i<N; i++) 
    total = total + arr[i];

    if(total & 1)
    return 0;

    return solveTab(arr, N, total/2);
}

//space opt kar lena yrr easy h 

