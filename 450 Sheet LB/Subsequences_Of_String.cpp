#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(string str, string output, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        ans.push_back(output);
        return;
    }

    solve(str, output, index + 1, ans);

    char ele = str[index];
    output.push_back(ele);
    solve(str, output, index + 1, ans);
}

vector<vector<int>> subsets(string str)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}