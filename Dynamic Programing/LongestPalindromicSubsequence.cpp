#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

//only rec
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

int longestPalindromeSubseq(string s)  {

    string revS = s;
    reverse(revS.begin(), revS.end());
    vector<vector<int>> dp(revS.length() + 1, vector<int> (revS.length(), -1));
    return solveMem(s, revS, 0, 0, dp);
}

//rec + mem
int solveTab(string &a, string &b) {

    vector<int> curr(a.length()+1, 0);
    vector<int> next(b.length()+1, 0);

    for(int i = a.length(); i>=0; i--) {

        for(int j = a.length(); j>=0; j--) {

            int ans = 0;

            if(a[i] == b[j]) 
            ans = 1 + next[j+1];

            else 
            ans = max(next[j], curr[j+1]);
            
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int longestPalindromeSubseq(string s)  {

    string revs = s;
    reverse(revs.begin(), revs.end());
    return solveTab(s, revs);
}


