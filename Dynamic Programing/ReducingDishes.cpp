#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>

using namespace std;

//only rec
int solve(vector<int>& satisfaction, int index, int time) {

    if(index >= satisfaction.size()) 
    return 0;

    int include = satisfaction[index]*time + solve(satisfaction, index+1, time+1);
    int exclude = 0 + solve(satisfaction, index+1, time);

    int ans = max(include, exclude);

    return ans;   
}

int maxSatisfaction(vector<int>& satisfaction) {

    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 1);
}

//rec + mem
int solveMem(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp) {

    if(index >= satisfaction.size()) 
    return 0;

    if(dp[index][time] != -1)
    return dp[index][time];

    int include = satisfaction[index]*time + solveMem(satisfaction, index+1, time+1, dp);
    int exclude = 0 + solveMem(satisfaction, index+1, time, dp);

    dp[index][time] = max(include, exclude);

    return dp[index][time];   
}

int maxSatisfaction(vector<int>& satisfaction) {

    vector<vector<int>> dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, -1));
    sort(satisfaction.begin(), satisfaction.end());
    return solveMem(satisfaction, 0, 1, dp);
}

// Tabulation
int solveTab(vector<int>& satisfaction) {

    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int index = n; index>=0; index--) {
        for(int time = index; time>=0; time--) {
    
            int include = satisfaction[index]*(time+1) + dp[index+1][time+1];
            int exclude = 0 + dp[index+1][time]; 

            dp[index][time] = max(include, exclude);
        }
    }

    return dp[0][0]; 
}

int maxSatisfaction(vector<int>& satisfaction) {

    sort(satisfaction.begin(), satisfaction.end());
    return solveTab(satisfaction);
}

//space Optimization
int solveOpt(vector<int>& satisfaction) {

    int n = satisfaction.size();
    vector<int> next(n+1, 0);
    vector<int> curr(n+1, 0);
    for(int index = n; index>=0; index--) {
        for(int time = index; time>=0; time--) {
    
            int include = satisfaction[index]*(time+1) + next[time+1];
            int exclude = 0 + next[time]; 

            curr[time] = max(include, exclude);
        }
        next = curr;
    }

    return next[0]; 
} 

int maxSatisfaction(vector<int>& satisfaction) {

    sort(satisfaction.begin(), satisfaction.end());
    return solveOpt(satisfaction);
}




 
