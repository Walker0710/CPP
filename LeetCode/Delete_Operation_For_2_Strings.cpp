#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

// rec only
int solve(string text1, string text2, int index1, int index2)
{

    if (index1 >= text1.length() || index2 >= text2.length())
        return 0;

    int ans = 0;

    if (text1[index1] == text2[index2])
        ans = 1 + solve(text1, text2, index1 + 1, index2 + 1);

    else
        ans = max(solve(text1, text2, index1 + 1, index2), solve(text1, text2, index1, index2 + 1));

    return ans;
}

int minDistance(string word1, string word2)
{
    int lcs = solve(word1, word2, 0, 0);
    return (lcs - word1.length()) + (lcs - word2.length());
}

// rec + mem
int solveMem(string text1, string text2, int index1, int index2, vector<vector<int>> &dp)
{

    if (index1 >= text1.length() || index2 >= text2.length())
        return 0;

    if (dp[index1][index2] != -1)
        return dp[index1][index2];

    int ans = 0;

    if (text1[index1] == text2[index2])
        ans = 1 + solveMem(text1, text2, index1 + 1, index2 + 1, dp);

    else
        ans = max(solveMem(text1, text2, index1 + 1, index2, dp), solveMem(text1, text2, index1, index2 + 1, dp));

    return dp[index1][index2] = ans;
}
int minDistance(string word1, string word2)
{

    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length(), -1));
    int lcs = solveMem(word1, word2, 0, 0, dp);
    return (word1.length() - lcs) + (word2.length() - lcs);
}

// tabulation
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length(), 0));

    for (int index1 = word1.length() - 1; index1 >= 0; index1--)
    {

        for (int index2 = word2.length() - 1; index2 >= 0; index2--)
        {

            int ans = 0;

            if (word1[index1] == word2[index2])
                ans = 1 + dp[index1 + 1][index2 + 1];

            else
                ans = max(dp[index1 + 1][index2], dp[index1][index2 + 1]);

            dp[index1][index2] = ans;
        }
    }
    return word1.length() - dp[0][0] + word2.length() - dp[0][0]; 
}
