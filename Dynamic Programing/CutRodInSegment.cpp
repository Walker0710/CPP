#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

//Rec only
int solveRec(int n, int x, int y, int z) {

    if(n == 0)
    return 0;

    if(n < 0)
    return INT_MIN; 

    int a = solveRec(n-x, x, y, z) + 1;
    int b = solveRec(n-y, x, y, z) + 1;
    int c = solveRec(n-z, x, y, z) + 1;

    int ans = max(a, max(b, c));
    return ans;
}

int cutSegments(int n, int x, int y, int z) {

    int ans = solveRec(n, x, y, z);

    if(ans != INT_MIN)
    return -1;

    return ans;
}

//Rec + Memo
int solveRec3(int n, int x, int y, int z, vector<int> &dp) {

    if(n == 0)
    return 0;

    if(n < 0)
    return INT_MIN; 

    if(dp[n] != -1) 
    return dp[n];

    int a = solveRec(n-x, x, y, z) + 1;
    int b = solveRec(n-y, x, y, z) + 1;
    int c = solveRec(n-z, x, y, z) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {

    vector<int> dp(n+1);
    
    for(int i = 0; i<=n; i++) 
    dp[i] = -1;

    int ans = solveRec3(n, x, y, z, dp);
    return ans;
}

//Tabulation
int cutSegments(int n, int x, int y, int z) {

    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;

    int a = INT_MIN;
    int b = INT_MIN;
    int c = INT_MIN;

    for(int i = 1; i<=n; i++) {

        if(i>=x)
        a = dp[i-x] + 1;

        if(i>=y)
        b = dp[i-y] + 1;

        if(i>=z)
        c = dp[i-z] + 1;

        dp[i] = max(a, max(b, c));
    }

    if(dp[n] < 0)
    return 0;

    return dp[n];
}
