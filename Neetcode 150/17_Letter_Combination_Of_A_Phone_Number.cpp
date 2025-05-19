#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(int index, string &digits, vector<string> &mp, string &toPush, vector<string> &ans) {
    if(index >= digits.length()) {
        ans.push_back(toPush);
        return ;
    }

    int ele = digits[index] - '0';

    string yoo = mp[ele];

    for(int j = 0; j<yoo.length(); j++) {
        toPush.push_back(yoo[j]);
        solve(index+1, digits, mp, toPush, ans);
        toPush.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    
    if(digits.empty())
    return ans;

    string toPush;

    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    solve(0, digits, mp, toPush, ans);

    return ans;
}