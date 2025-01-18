#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(string s, unordered_set<string> &ans, int index)
{
    // base case
    if (index >= s.length())
    {
        ans.insert(s);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        swap(s[index], s[i]);
        solve(s, ans, index + 1);

        swap(s[index], s[i]); 
    }
}

vector<string> findPermutation(string &s)
{
    unordered_set<string> ans;
    int index = 0;

    solve(s, ans, index);

    vector<string> yoo;

    for(auto it : ans) {
        yoo.push_back(it);
    }

    sort(yoo.begin(), yoo.end());

    return yoo;
}