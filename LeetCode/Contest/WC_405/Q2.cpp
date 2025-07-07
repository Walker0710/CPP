#include <bits/stdc++.h>

using namespace std;

// << ,

void solve(int index, int n, bool flag, string curr, vector<string> &ans) {
    if(index ==  n) {
        ans.push_back(curr);
        return ;
    }

    if(flag) {
        solve(index + 1, n, flag, curr + '1', ans);
        solve(index + 1, n, !flag, curr + '0', ans);
    }

    else {
        solve(index+1, n, !flag, curr + '1', ans);
    }
    
}

vector<string> validStrings(int n)
{
    vector<string> ans;

    solve(0, n, true, "", ans);

    return ans;
}