#include <bits/stdc++.h>

using namespace std;

// << ,

bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries, int k)
{
    int n = nums.size();
    vector<int> diff(n, 0);

    for (int i = 0; i < k; i++)
    {
        diff[queries[i][0]] += queries[i][2];

        if (queries[i][1] + 1 < n)
            diff[queries[i][1] + 1] -= queries[i][2];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cnt = cnt + diff[i];

        if (nums[i] > cnt)
            return false;
    }

    return true;
}

int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();

    int st = 0;
    int en = queries.size();

    if(!isZeroArray(nums, queries, queries.size()))
    return -1;

    while (st < en)
    {
        int mid = st + (en - st)/2;

        if(isZeroArray(nums, queries, mid)) {
            en = mid;
        }

        else {
            st = mid+1;
        }
    }

    return st;
    
}