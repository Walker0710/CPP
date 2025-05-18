#include <bits/stdc++.h>

using namespace std;

// << ,

bool isPalindrome(string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void solve(int index, string &s, vector<string> &toPush, vector<vector<string>> &ans)
{
    if (index >= s.length())
    {
        ans.push_back(toPush);
        return;
    }

    for (int j = index; j < s.length(); j++)
    {
        if (isPalindrome(s, index, j))
        {
            toPush.push_back(s.substr(index, j - index + 1));
            solve(j + 1, s, toPush, ans);
            toPush.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> toPush;
    solve(0, s, toPush, ans);

    return ans;
}