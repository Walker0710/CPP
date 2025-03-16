#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 1)
    {
        return 0;
    }

    int ans = -1;
    sort(intervals.begin(), intervals.end(), [](auto const &a, auto const &b) { return a[1] < b[1]; });

    vector<int> prev = intervals[0];

    for (auto it : intervals)
    {
        if (it[0] < prev[1])
        {
            ans++;
        }
        else
        {
            prev = it;
        }
    }
    return ans;
}