#include<iostream>
#include<vector>

using namespace std;

//so basicly there are 2 ways 
//1st way Top-Down == recursion + memoization
//2nd way Bottom-Up == Tabulation


//1st approch top down
int fib(int n, vector<int> &dp) {

    if(n == 1 || n == 0) 
    return n;

    if(dp[n] != -1) 
    return dp[n];

    dp[n] = fib(n-1, dp) + fib(n-2, dp);

    return dp[n];
}

int main() {

    int n;
    cin>>n;

    vector<int> dp(n+1);

    for(int i = 0; i<=n; i++) 
    dp[i] = -1;

    cout<<fib(n, dp) << endl;

    return 0;
}

//2nd approch bottom up
int main() {

    int n;
    cin>>n;

    vector<int> dp(n+1);

    dp[1] = 1;
    dp[0] = 0;

    for(int i = 2; i<=n; i++) 
    dp[i] = dp[i-1] + dp[i-2];

    cout<< dp[n] << endl;
}

//2nd with space optimization
int main() {

    int n;
    cin>>n;
    int prev1 = 1;
    int prev2 = 0;

    for(int i = 0; i<=n; i++) {

        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    cout<<prev1<<endl;
}