#include <bits/stdc++.h>

using namespace std;

// << ,
unordered_map<string, string> dp;

string rec(int i, int j, string &str1, string &str2)
{
    string key = to_string(i) + "+" + to_string(j);

    if (i == str1.length())
    {
        return str2.substr(j);
    }
    if (j == str2.length())
    {
        return str1.substr(i);
    }

    if (dp.count(key))
    {
        return dp[key];
    }

    if (str1[i] == str2[j])
    {
        return dp[key] = str1[i] + rec(i + 1, j + 1, str1, str2);
    }

    string op1 = str1[i] + rec(i + 1, j, str1, str2);

    string op2 = str2[j] + rec(i, j + 1, str1, str2);

    return dp[key] = (op1.length() < op2.length()) ? op1 : op2;
}

string shortestCommonSupersequence(string str1, string str2)
{
    string ans = rec(0, 0, str1, str2);

    return ans;
}




string solve1(int pos1, int pos2, string str1, string str2, vector<vector<string>> &dp)
{

    if (pos1 >= str1.size() && pos2 >= str2.size())
    {
        return "";
    }
    if (pos1 >= str1.size())
    {
        return str2.substr(pos2);
    }

    if (pos2 >= str2.size())
    {
        return str1.substr(pos1);
    }
    if (dp[pos1][pos2] != "-1")
    {
        return dp[pos1][pos2];
    }

    string tempAns;
    if (str1[pos1] == str2[pos2])
    {
        tempAns = str2[pos2] + solve1(pos1 + 1, pos2 + 1, str1, str2, dp);
    }
    else
    {
        string temp1 = str1[pos1] + solve1(pos1 + 1, pos2, str1, str2, dp);
        string temp2 = str2[pos2] + solve1(pos1, pos2 + 1, str1, str2, dp);

        if (temp1.size() < temp2.size())
        {
            tempAns = temp1;
        }
        else
        {
            tempAns = temp2;
        }
    }
    return dp[pos1][pos2] = tempAns;
}

string shortestCommonSupersequence(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<string>> dp(m + 1, vector<string>(n + 1, "-1"));

    return solve1(0, 0, str1, str2, dp);
}







string shortestCommonSupersequence(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (str1[i] == str2[j])
            {
                dp[i + 1][j + 1] = 1 + dp[i][j];
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    string res;
    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            res += str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            res += str1[i - 1];
            i--;
        }
        else
        {
            res += str2[j - 1];
            j--;
        }
    }

    while (i > 0)
        res += str1[--i];
    while (j > 0)
        res += str2[--j];

    reverse(res.begin(), res.end());
    return res;
}