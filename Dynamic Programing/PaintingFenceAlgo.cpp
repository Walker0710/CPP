#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

//only Rec
int add(int a, int b) {

    return (a%MOD + b%MOD)%MOD;
}

int multi(int a, int b) {

    return (a%MOD * 1LL * b%MOD)%MOD;
}

int solve(int n, int k) {

    if(n == 1)
    return k;

    if(n == 2)
    return add(k, multi(k, k-1));

    int ans = add(multi(solve(n-2, k), k-1), multi(solve(n-1, k), k-1));
    return ans;
}

int numberOfWays(int n, int k) {

    int ans = solve(n, k);
    return ans;
}

//Rec + memo
int add(int a, int b) {

    return (a%MOD + b%MOD)%MOD;
}

int multi(int a, int b) {

    return (a%MOD * 1LL * b%MOD)%MOD;     //The ints are not promoted to long long before multiplication, they remain ints and their product as well. 
                                          //Then the product is cast to long long, but we are late now as overflow has already occurred. 
                                          //Having one of x or y as long long should would work, as the other would be promoted. We can also use 1LL (or 1ll).
}

int solve(int n, int k, vector<int> &dp) {

    if(n == 1)
    return k;

    if(n == 2)
    return add(k, multi(k, k-1));

    if(dp[n] != -1)
    return dp[n];

    dp[n] = add(multi(solve(n-2, k, dp), k-1), multi(solve(n-1, k, dp), k-1));
    return dp[n];
}

int numberOfWays(int n, int k) {

    vector<int> dp(n+1, -1);
    int ans = solve(n, k, dp);
    return ans;
}

//Tabulation
int add(int a, int b) {

    return (a%MOD + b%MOD)%MOD;
}

int multi(int a, int b) {

    return (a%MOD * 1LL * b%MOD)%MOD;
}

int numberOfWays(int n, int k) {

    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = add(k, multi(k, k-1));

    for(int i = 3; i<=n; i++) {

        dp[i] = add(multi(dp[i-2], k-1), multi(dp[i-1], k-1));
    }

    return dp[n];
}

// Tabulation with space optimization
int add(int a, int b) {

    return (a%MOD + b%MOD)%MOD;
}

int multi(int a, int b) {

    return (a%MOD * 1LL * b%MOD)%MOD;
}

int numberOfWays(int n, int k) {

    int prev2 = k;
    int prev1 = add(k, multi(k, k-1));

    for(int i = 3; i<=n; i++) {

        int curr = add(multi(prev2, k-1), multi(prev1, k-1));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

