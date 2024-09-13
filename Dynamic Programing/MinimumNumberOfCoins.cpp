#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

//my approch
int solve(vector<int> &num, int x, vector<int> &record) {

    if(x == 0)
    return 1;

    if(x < 0)
    return INT_MAX;

    for(int i = 0; i<num.size(); i++) 
    record[i] = solve(num, x - num[i], record) + record[i];
    
    int ans = *min_element(record.begin(), record.end());
    return ans;
}

int minimumElements(vector<int> &num, int x) {

    vector<int> record(num.size(), 0);

    int ans = solve(num, x, record);
    return ans;
}

//babbars's approch

//only rec
int solveRec(vector<int> &num, int x) {

    if(x == 0) 
    return 0;

    if(x < 0)
    return INT_MAX;

    int mini = INT_MAX;

    for(int i = 0; i<num.size(); i++) {

        int ans = solveRec(num, x-num[i]);

        if(ans != INT_MAX)
        mini = min(mini, 1+ans);
    }

    return mini;
}

int minimumElements(vector<int> &num, int x) {

    int ans = solveRec(num, x);
    
    if(ans == INT_MAX)
    return -1;

    return ans;
}

//rec + memos
int solveRec(vector<int> &num, int x, vector<int> &dp) {

    if(x == 0) 
    return 0;

    if(x < 0)
    return INT_MAX;

    int mini = INT_MAX;

    if(dp[x] != -1)
    return dp[x];

    for(int i = 0; i<num.size(); i++) {

        int ans = solveRec(num, x-num[i]);

        if(ans != INT_MAX)
        mini = min(mini, 1+ans);
    }
 
    dp[x] = mini;
    return mini;
}

int minimumElements(vector<int> &num, int x) {

    vector<int> dp(num.size() + 1, -1);
    int ans = solveRec(num, x, dp);

    if(ans == INT_MAX)
    return -1;

    return ans;
}

//tabulation
int minimumElements(vector<int> &num, int x) {

    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i<=x; i++) {

        //trying to solve for  every amount figure 1 to x
        for(int j = 0; j<num.size(); j++) {
            
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
            dp[i] = min(dp[i], 1 + dp[i-num[j]]);
        }
    }

    if(dp[x] == INT_MAX)
    return -1;

    return dp[x];
}
