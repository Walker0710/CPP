#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// 1st approch
bool solve(string &s1, string &s2, string &s3, int index1, int index2, int index3)
{

    if (index1 >= s1.length() && index2 >= s2.length() && index3 >= s3.length())
        return true;

    if ((s1[index1] != s3[index3] && s2[index2] != s3[index3]) || (index1 >= s1.length() && index3 >= s3.length() && index2 < s2.length()) || (index2 >= s2.length() && index3 >= s3.length() && index1 < s1.length()) || (index1 >= s1.length() && index2 >= s2.length() && index3 < s3.length()))
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

// 2nd approch - how this is diffrent from 3 approch
bool solve2(string &s1, string &s2, string &s3, int index1, int index2, int index3)
{

    if (index1 == s1.length() && index2 == s2.length() && index3 == s3.length())
        return true;

    if (index3 == s3.length())
        return false;

    bool first = false;
    bool second = false;

    if (s1[index1] == s3[index3] || s2[index2] == s3[index3])
    {

        first = solve2(s1, s2, s3, index1 + 1, index2, index3 + 1);
        second = solve2(s1, s2, s3, index1, index2 + 1, index3 + 1);
    }

    return first || second;
}

// 3rd approch
bool solve3(string &s1, string &s2, string &s3, int index1, int index2, int index3)
{

    if (index1 == s1.length() && index2 == s2.length() && index3 == s3.length())
        return true;

    if (index3 == s3.length())
        return false;

    bool first = false;
    if (index1 < s1.length() && s1[index1] == s3[index3])
        first = solve3(s1, s2, s3, index1 + 1, index2, index3 + 1);

    bool second = false;
    if (!first && index2 < s2.length() && s2[index2] == s3[index3])
        second = solve3(s1, s2, s3, index1, index2 + 1, index3 + 1);

    return first || second;
}

bool isInterleave(string s1, string s2, string s3)
{

    return solve3(s1, s2, s3, 0, 0, 0);
}

// rec + mem
bool solveMem(string &s1, string &s2, string &s3, int index1, int index2, int index3, vector<vector<vector<int>>> dp)
{

    if (index1 == s1.length() && index2 == s2.length() && index3 == s3.length())
        return true;

    if (index3 == s3.length())
        return false;

    if (dp[index1][index2][index3] != -1)
        return dp[index1][index2][index3];

    bool first = false;
    if (index1 < s1.length() && s1[index1] == s3[index3])
        first = solveMem(s1, s2, s3, index1 + 1, index2, index3 + 1, dp);

    bool second = false;
    if (!first && index2 < s2.length() && s2[index2] == s3[index3])
        second = solveMem(s1, s2, s3, index1, index2 + 1, index3 + 1, dp);

    return dp[index1][index2][index3] = first || second;
}

bool isInterleave(string s1, string s2, string s3)
{

    vector<vector<vector<int>>> dp(s1.length() + 1, vector<vector<int>>(s2.length() + 1, vector<int>(s3.length() + 1, -1)));
    return solveMem(s1, s2, s3, 0, 0, 0, dp);
}

// using 2d matrix
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

// Tabulation
bool solveTab(string &s1, string &s2, string &s3)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    dp[s1.length()][s2.length()] = 1;

    for (int index1 = s1.length() - 1; index1 >= 0; index1--)
    {

        for (int index2 = s2.length() - 1; index2 >= 0; index2--)
        {

            for (int index3 = s3.length() - 1; index3 >= 0; index3--)
            {
                bool first = false;
                if (index1 < s1.length() && s1[index1] == s3[index3])
                    first = dp[index1 + 1][index2];

                bool second = false;
                if (!first && index2 < s2.length() && s2[index2] == s3[index3])
                    second = dp[index1][index2 + 1];
            }
        }
    }

    return dp[0][0];
}

bool isInterleave(string s1, string s2, string s3)
{

    return solveTab(s1, s2, s3);
}
