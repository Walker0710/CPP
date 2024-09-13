#include<iostream>
#include<vector>

using namespace std;

int solve2(int nStairs, int i) {

    if(i == 1) 
    return 1;

    if(i <= 0)
    return 0;

    return (solve2(nStairs, i-1) + solve2(nStairs, i-2));
}

int countDistinctWays2(int nStairs) {

    int ans = solve(nStairs, nStairs);
    return ans;
}

int solve(int nStairs, int i) {

    if(i == nStairs)
    return 1;

    if(i > nStairs)
    return 0;

    return (solve(nStairs, i+1) + solve(nStairs, i+2));
}

int countDistinctWays(int nStairs) {

    int ans = solve(nStairs, 0);
    return ans;
}

//actual question

//1st approch - Top - Down approch
int solvee(vector<int> &cost, int i, vector<int> &dp) {

    if(i == 0 || i == 1) 
    return cost[i];

    if(dp[i] != -1) 
    return dp[i];

    dp[i] = min(solvee(cost, i-1, dp), solvee(cost, i-2, dp)) + cost[i]; 

    return dp[i];
}

int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    vector<int> dp(n+1);

    for(int i = 0; i<n; i++)
    dp[i] = -1;

    int ans = min(solvee(cost, n-1, dp), solvee(cost, n-2, dp));
    return ans;
}

//2nd approch - Bottom Up approch
int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    vector<int> dp(n+1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i<n; i++) {

        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }

    return min(dp[n-1], dp[n-2]);
}

//bottom up with space optimization
int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    int prev1 = cost[1];
    int prev2 = cost[0];

    for(int i = 2; i < n; i++) {

        int curr = min(prev1, prev2) + cost[i];

        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}


