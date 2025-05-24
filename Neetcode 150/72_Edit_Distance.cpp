#include <bits/stdc++.h>

using namespace std;

// << ,

// rec + mem
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

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
    return solveMem(word1, word2, 0, 0, dp);
}

// tabulation

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

    for (int j = 0; j <= word2.length(); j++)
    {
        dp[word1.length()][j] = word2.length() - j;
    }
    
    for (int i = 0; i <= word1.length(); i++)
    {
        dp[i][word2.length()] = word1.length() - i;
    }

    for (int index1 = word1.length() - 1; index1 >= 0; index1--)
    {
        for (int index2 = word2.length() - 1; index2 >= 0; index2--)
        {
            int ans = 0;

            if (word1[index1] == word2[index2])
                ans = dp[index1 + 1][index2 + 1];

            else
            {
                int insertAns = 1 + dp[index1][index2 + 1];
                int deleteAns = 1 + dp[index1 + 1][index2];
                int replaceAns = 1 + dp[index1 + 1][index2 + 1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }

            dp[index1][index2] = ans;
        }
    }

    return dp[0][0];
}