#include <bits/stdc++.h>

using namespace std;

// << ,

int solveMem(string &s, int index, vector<int> &dp) {

    if(index == s.length()) 
    return 1;

    if(index > s.length() || s[index] == '0')
    return 0;

    if(dp[index] != -1)
    return dp[index];

    int ans = 0;

    if(s[index+1] != '0')
    ans = ans + solveMem(s, index+1, dp);

    if(index + 1 < s.length() && ((s[index] == '1') || (s[index] == '2' && s[index + 1] <= '6'))) 
    ans =  ans + solveMem(s, index+2, dp);

    return dp[index] = ans;
}

int numDecodings(string s) {

    if(s.empty() || s[0] == '0')
    return 0;

    else {
        vector<int> dp(s.length() + 1, -1);
        return solveMem(s, 0, dp);
    }
}