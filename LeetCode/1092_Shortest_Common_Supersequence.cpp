#include <bits/stdc++.h>

using namespace std;

// << ,

string helper(string str1, string str2, unordered_map<string, string> &memo)
{
    string memoKey = str1 + " " + str2;

    if (memo.find(memoKey) != memo.end())
    {
        return memo[memoKey];
    }

    if (str1.empty() && str2.empty())
    return "";

    if (str1.empty())    
    return str2;

    if (str2.empty())
    return str1;

    if (str1[0] == str2[0])
    {
        return memo[memoKey] = str1[0] + helper(str1.substr(1), str2.substr(1), memo);
    }

    string pickStr1 = str1[0] + helper(str1.substr(1), str2, memo);
    string pickStr2 = str2[0] + helper(str1, str2.substr(1), memo);

    return memo[memoKey] = (pickStr1.length() < pickStr2.length()) ? pickStr1 : pickStr2;
}

string shortestCommonSupersequence(string str1, string str2)
{
    unordered_map<string, string> memo;
    return helper(str1, str2, memo);
}