#include <bits/stdc++.h>

using namespace std;

// << ,

vector<vector<int>> merge(vector<vector<int>> intervals)
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

int countDays(int days, vector<vector<int>> &meetings)
{
    vector<vector<int>> ans = merge(meetings);

    int yoo = ans[0][0] - 1;

    for(int i = 0; i<ans.size() - 1; i++) {
        if(ans[i+1][0] <= days) {
            yoo = yoo + ans[i+1][0] - ans[i][1] - 1; 
        }

        else if(ans[i][1] <= days && ans[i+1][0] > days) {
            yoo = yoo + ans[i][0] - days;
            break;
        }
    }

    if(ans[ans.size()-1][1] < days) {
        yoo = yoo + days - ans[ans.size() - 1];
    }

    return yoo;
}