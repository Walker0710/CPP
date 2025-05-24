#include <bits/stdc++.h>

using namespace std;

// << ,

bool solve(string &s1, string &s2, string &s3, int index1, int index2, int index3)
{

    if (index1 >= s1.length() && index2 >= s2.length() && index3 >= s3.length())
        return true;

    if (s1[index1] != s3[index3] && s2[index2] != s3[index3])
        return false;

    while (index3 < s3.length() && index1 < s1.length() && s3[index3] == s1[index1])
    {
        index1++;
        index3++;
    }

    while (index3 < s3.length() && index2 < s2.length() && s3[index3] == s2[index2])
    {
        index2++;
        index3++;
    }

    bool ans = solve(s1, s2, s3, index1, index2, index3);

    return ans;
}

bool isInterleave(string s1, string s2, string s3)
{

    return solve(s1, s2, s3, 0, 0, 0);
}

bool solveMem2(string &s1, string &s2, string &s3, int index1, int index2, int index3, vector<vector<int>> &dp)
{

    if (index1 == s1.length() && index2 == s2.length() && index3 == s3.length())
        return true;

    if (index3 == s3.length())
        return false;

    if (dp[index1][index2] != -1)
        return dp[index1][index2];

    bool first = false;
    if (index1 < s1.length() && s1[index1] == s3[index3])
        first = solveMem2(s1, s2, s3, index1 + 1, index2, index3 + 1, dp);

    bool second = false;
    if (!first && index2 < s2.length() && s2[index2] == s3[index3])
        second = solveMem2(s1, s2, s3, index1, index2 + 1, index3 + 1, dp);

    return dp[index1][index2] = first || second;
}

bool isInterleave(string s1, string s2, string s3)
{

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return solveMem2(s1, s2, s3, 0, 0, 0, dp);
}



// tabulation
bool isInterleave(string s1, string s2, string s3)
{
    int m = s1.length(), n = s2.length();
    if (m + n != s3.length())
    {
        return false;
    }

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[m][n] = true;

    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i < m && s1[i] == s3[i + j] && dp[i + 1][j])
            {
                dp[i][j] = true;
            }
            if (j < n && s2[j] == s3[i + j] && dp[i][j + 1])
            {
                dp[i][j] = true;
            }
        }
    }
    return dp[0][0];
}