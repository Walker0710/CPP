#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

//rec + mem
int solve(int n, int k, int target) {

    if(target < 0)
    return 0;

    if(n == 0 && target != 0)
    return 0;

    if(target == 0 && n != 0)
    return 0;

    if(target == 0 && n == 0)
    return 1;

    int ans = 0;

    for(int i = 1; i<=k; i++) {
        ans = (ans + solve(n-1, k, target - i)) % (1000000007);
    }

    return ans;
}

int numRollsToTarget(int n, int k, int target) {
    return solve(n, k, target);
}

//rec + mem
int solveMem(int n, int k, int target, vector<vector<int>> &dp) {

    if(target < 0)
    return 0;

    if(n == 0 && target != 0)
    return 0;

    if(target == 0 && n != 0)
    return 0;

    if(target == 0 && n == 0)
    return 1;

    if(dp[n][target] != -1)
    return dp[n][target];

    int ans = 0;

    for(int i = 1; i<=k; i++) {
        ans = (ans + solveMem(n-1, k, target - i, dp)) % (1000000007);
    }
    return dp[n][target] = ans;
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n+1, vector<int> (target + 1, -1));
    return solveMem(n, k, target, dp);
}