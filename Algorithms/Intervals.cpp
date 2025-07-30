#include <bits/stdc++.h>

using namespace std;

// << ,

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size(), i = 0;
    vector<vector<int>> res;

    while (i < n && intervals[i][1] < newInterval[0])
    {
        res.push_back(intervals[i]);
        i++;
    }

    while (i < n && newInterval[1] >= intervals[i][0])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    res.push_back(newInterval);

    while (i < n)
    {
        res.push_back(intervals[i]);
        i++;
    }
    
    return res;
}


vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
    {
        return {};
    }

    sort(intervals.begin(), intervals.end());

    int numberOfInterval = intervals.size();
    vector<vector<int>> ans;

    int i = 0;
    while (i < numberOfInterval)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        while (i + 1 < numberOfInterval && intervals[i + 1][0] <= end)
        {
            end = max(end, intervals[i + 1][1]);
            i++;
        }

        ans.push_back({start, end});
        i++;
    }

    return ans;
}





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