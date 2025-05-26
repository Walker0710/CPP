#include <bits/stdc++.h>

using namespace std;

// << ,

// some issues
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    bool flag = false;
    int i = 0;

    while (i < intervals.size())
    {

        if (!flag && intervals[i][1] > newInterval[0])
        {
            flag = true;

            int startPt = min(intervals[i][0], newInterval[0]);

            while (intervals[i][1] < newInterval[1])
            {
                i++;
            }

            int endPt = 0;

            if (intervals[i][0] <= newInterval[1])
            {
                endPt = intervals[i][1];
                ans.push_back({startPt, endPt});
            }

            else
            {
                endPt = newInterval[1];
                ans.push_back({startPt, endPt});
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }

        else
        {
            ans.push_back(intervals[i]);
        }

        i++;
    }

    return ans;
}


// good approch
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