#include <bits/stdc++.h>

using namespace std;

// << ,

int solveMem(string &word1, string &word2, int index1, int index2, vector<vector<int>> &dp)
{

    if (index1 == word1.length())
        return word2.length() - index2;

    if (index2 == word2.length())
        return word1.length() - index1;

    if (dp[index1][index2] != -1)
        return dp[index1][index2];

    int ans = 0;

    if (word1[index1] == word2[index2])
        ans = solveMem(word1, word2, index1 + 1, index2 + 1, dp);

    else
    {
        int insertAns = 1 + solveMem(word1, word2, index1, index2 + 1, dp);
        int deleteAns = 1 + solveMem(word1, word2, index1 + 1, index2, dp);
        int replaceAns = 1 + solveMem(word1, word2, index1 + 1, index2 + 1, dp);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return dp[index1][index2] = ans;
}

int editDistance(string &word1, string &word2)
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
    return solveMem(word1, word2, 0, 0, dp);
}