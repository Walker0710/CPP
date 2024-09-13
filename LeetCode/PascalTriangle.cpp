#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

void solve(int numRows, int r, vector<vector<int>> &ans) {

    if(r == numRows)
    return;

    vector<int> toPush(r+1, 0);
    toPush[0] = 1;

    for (int i = 1; i < r; i++) {
        int first = (i < ans[r - 1].size()) ? ans[r - 1][i] : 0;
        int sec = (i - 1 >= 0) ? ans[r - 1][i - 1] : 0;
        toPush[i] = first + sec;
    }

    toPush[r] = 1;
    ans.push_back(toPush);

    solve(numRows, r+1, ans);
}

vector<vector<int>> generate(int numRows) {

    vector<vector<int>> ans;
    vector<int> yo(1, 1);
    ans.push_back(yo);
    solve(numRows, 1, ans);
    return ans;
}

