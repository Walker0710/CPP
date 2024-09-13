#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

// Rec only
int solve(int n) {

    if(n == 1) 
    return 0;

    if(n == 2)
    return 1;

    return (n-1)%MOD*(solve(n-1)%MOD + solve(n-2)%MOD);
}

long long int countDerangements(int n) {

    int ans = solve(n);
    return ans;
}

//Rec + memo
long long int solve(int n, vector<long long int> &dp) {

    if(n == 1) 
    return 0;

    if(n == 2)
    return 1;

    if(dp[n] != -1)
    return dp[n];

    dp[n] = (n-1)%MOD*(solve(n-1, dp)%MOD + solve(n-2, dp)%MOD);
    return dp[n];
}

long long int countDerangements(int n) {

    vector<long long int> dp(n+1, -1);
    return solve(n,dp);
}

//tabulation
long long int countDerangements(int n) {

    vector<long long int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1; 

    for(int i = 3; i <= n; i++) {

        dp[i] = ((i-1)*(dp[i-1]%MOD + dp[i-2]%MOD))%MOD;
    }

    return dp[n];
}

//babbar approch
long long int countDerangements(int n) {

    vector<long long int> dp(n+1, 0);
    dp[1] = 0; 
    dp[2] = 1;

    for(int i = 3; i<=n; i++) {

        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        long long int sum = (first + second)%MOD;

        long long int ans = ((n-1)*sum)%MOD;
        dp[i] = ans;
    }

    return dp[n];
}

// tabultion with space optimization
long long int countDerangements(int n) {

    int prev2 = 0;
    int prev1 = 1;

    for(int i = 3; i<=n; i++) {

        int curr = ((i-1)*(prev1%MOD + prev2%MOD))%MOD;
        
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}