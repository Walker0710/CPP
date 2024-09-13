#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

int solve(int n) {

    if(n == 0 || n == 1) 
    return 1;

    int ans = solve(n-1) + solve(n-2);

    return ans;
}

int climbStairs(int n) {

    return solve(n);
}

//mem + rec
int solveMem(int n, vector<int> &dp) {

    if(n == 0)
    return 1;

    if(n < 0)
    return 0;

    if(dp[n] != -1) 
    return dp[n];

    int ans = solveMem(n-1, dp) + solveMem(n-2, dp);

    return dp[n] = ans;
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return solveMem(n, dp);
}


//2nd appproch
int solve2(int n, int index) {

    if(index == n)
    return 1;

    if(index > n)
    return 0;

    int ans = solve2(n, index + 1) + solve2(n , index + 2);

    return ans;
}

int climbStairs(int n) {

    return solve2(n, 0);
}

