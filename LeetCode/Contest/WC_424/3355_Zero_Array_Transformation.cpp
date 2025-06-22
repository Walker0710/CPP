#include <bits/stdc++.h>

using namespace std;

// << ,

// sweep line

bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    vector<int> diff(n, 0);

    for(int i = 0; i<queries.size(); i++) {
        diff[queries[i][0]]++;

        if(queries[i][1] + 1 < n)
        diff[queries[i][1] + 1]--;
    }

    int cnt = 0;

    for(int i = 0; i<n; i++) {
        cnt = cnt + diff[i];

        if(nums[i] > cnt)
        return false;
    }

    return true;
}