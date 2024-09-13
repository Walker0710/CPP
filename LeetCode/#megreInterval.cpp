#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    if (intervals.empty()) {
        return {};
    }

    sort(intervals.begin(), intervals.end());

    int numberOfInterval = intervals.size();
    vector<vector<int>> ans;

    int i = 0;
    while (i < numberOfInterval) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Check for overlapping intervals and merge them
        while (i + 1 < numberOfInterval && intervals[i + 1][0] <= end) {
            end = max(end, intervals[i + 1][1]);
            i++;
        }

        ans.push_back({start, end});
        i++;
    }

    return ans;
}



