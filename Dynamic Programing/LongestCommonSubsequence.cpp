#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

//only rec
int solve(string text1, string text2, int index1, int index2) {

    if(index1 >= text1.length() || index2 >= text2.length()) 
    return 0;

    int ans = 0;

    if(text1[index1] == text2[index2]) 
    ans = 1 + solve(text1, text2, index1 + 1, index2 + 1);

    else 
    ans = max(solve(text1, text2, index1 + 1, index2), solve(text1, text2, index1, index2 + 1));

    return ans;
}

int longestCommonSubsequence(string text1, string text2) {

    return solve(text1, text2, 0, 0);
}

//rec + mem
int solveMem(string text1, string text2, int index1, int index2, vector<vector<int>> &dp) {

    if(index1 >= text1.length() || index2 >= text2.length()) 
    return 0;

    if(dp[index1][index2] != -1)
    return dp[index1][index2];

    int ans = 0;

    if(text1[index1] == text2[index2]) 
    ans = 1 + solveMem(text1, text2, index1 + 1, index2 + 1, dp);

    else 
    ans = max(solveMem(text1, text2, index1 + 1, index2, dp), solveMem(text1, text2, index1, index2 + 1, dp));

    return dp[index1][index2] = ans;
}

int longestCommonSubsequence(string text1, string text2) {

    vector<vector<int>> dp(text1.length() + 1, vector<int> (text2.length(), -1));
    return solveMem(text1, text2, 0, 0, dp);
}
