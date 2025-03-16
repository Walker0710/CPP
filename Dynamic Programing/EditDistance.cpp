#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

//only rec
int solve(string &word1, string &word2, int index1, int index2) {

    if(index1 == word1.length())
    return word2.length() - index2;

    if(index2 == word2.length())
    return word1.length() - index1;

    int ans = 0;

    if(word1[index1] == word2[index2])
    ans = solve(word1, word2, index1+1, index2+1);

    else {

        int insertAns = 1 + solve(word1, word2, index1, index2 + 1);
        int deleteAns = 1 + solve(word1, word2, index1 + 1, index2);
        int replaceAns = 1 + solve(word1, word2, index1+1, index2+1);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return ans;
}

int minDistance(string word1, string word2) {

    return solve(word1, word2, 0, 0);
}

//rec + mem
int solveMem(string &word1, string &word2, int index1, int index2, vector<vector<int>> &dp) {

    if(index1 == word1.length())
    return word2.length() - index2;

    if(index2 == word2.length())
    return word1.length() - index1;

    if(dp[index1][index2] != -1) 
    return dp[index1][index2];

    int ans = 0;

    if(word1[index1] == word2[index2])
    ans = solveMem(word1, word2, index1+1, index2+1, dp);

    else {

        int insertAns = 1 + solveMem(word1, word2, index1, index2 + 1, dp);
        int deleteAns = 1 + solveMem(word1, word2, index1 + 1, index2, dp);
        int replaceAns = 1 + solveMem(word1, word2, index1+1, index2+1, dp);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return ans;
}

int minDistance(string word1, string word2) {

    vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length()+1, -1));
    return solveMem(word1, word2, 0, 0, dp);
}

//tabulation
int solveTab(string &word1, string &word2) {

    vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length()+1, 0));

    for(int i = 0; i<=word2.length(); i++) 
    dp[word1.length()][i] = word2.length() - i;

    for(int i = 0; i<=word1.length(); i++) 
    dp[i][word2.length()] = word1.length() - i; 

    for(int i = word1.length()-1; i>=0; i++) {

        for(int j = word2.length() - 1; j>=0; j++) {

            int ans = 0;
            
            if(word1[i] == word2[j])
            ans = dp[i+1][j+1];

            else {

                int insertAns = 1 + dp[i][j+1];
                int deleteAns = 1 + dp[i+1][j];
                int replaceAns = 1 + dp[i+1][j+1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int minDistance(string word1, string word2) {

    return solveTab(word1, word2);
}

//sapce optimization

//wrong approch
int solveTab(string &word1, string &word2) {

    vector<int> next(word2.length()+1, 0);
    vector<int> curr(word2.length()+1, 0);

    for(int i = 0; i<=word2.length(); i++) 
    next[i] = word2.length() - i;

    next[word2.length()] = 0;
    curr[word2.length()] = 1;

    for(int i = word1.length()-1; i>=0; i--) {

        for(int j = word2.length() - 1; j>=0; j--) {

            int ans = 0;
            
            if(word1[i] == word2[j])
            ans = next[j+1];

            else {

                int insertAns = 1 + curr[j+1];
                int deleteAns = 1 + next[j];
                int replaceAns = 1 + next[j+1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int minDistance(string word1, string word2) {
    
    if(word1.length() == 0)
    return word2.length();

    if(word2.length() == 0)
    return word1.length();

    return solveTab(word1, word2);
}

//2nd approch
int solveTab(string &word1, string &word2) {

    vector<int> next(word2.length()+1, 0);
    vector<int> curr(word2.length()+1, 0);

    for(int i = 0; i<=word2.length(); i++) 
    next[i] = word2.length() - i;

    // next[word2.length()] = 0;
    // curr[word2.length()] = 1;

    for(int i = word1.length()-1; i>=0; i--) {

        for(int j = word2.length() - 1; j>=0; j--) {

            curr[word2.length()] = word1.length()-i;
            int ans = 0;
            
            if(word1[i] == word2[j])
            ans = next[j+1];

            else {

                int insertAns = 1 + curr[j+1];
                int deleteAns = 1 + next[j];
                int replaceAns = 1 + next[j+1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int minDistance(string word1, string word2) {

    if(word1.length() == 0)
    return word2.length();

    if(word2.length() == 0)
    return word1.length();

    return solveTab(word1, word2);
}



