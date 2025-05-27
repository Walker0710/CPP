#include <bits/stdc++.h>

using namespace std;

// << ,

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

vector<int> partitionLabels(string s)
{
    int n = s.length();

    unordered_map<char, int> startIndex;
    unordered_map<char, int> lastIndex;

    for (int i = 0; i < n; i++)
    {
        lastIndex[s[i]] = i;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        startIndex[s[i]] = i;
    }

    vector<vector<int>> intervals;

    for (int i = 0; i < n; i++)
    {
        intervals.push_back({startIndex[s[i]], lastIndex[s[i]]});
    }

    vector<vector<int>> yoo = merge(intervals);

    vector<int> ans;

    for (int i = 0; i < yoo.size(); i++)
    {
        ans.push_back(yoo[i][1] - yoo[i][0] + 1);
    }

    return ans;
}

// 2nd approch
vector<int> partitionLabels(string s)
{
    unordered_map<char, int> lastIndex;
    for (int i = 0; i < s.size(); i++)
    {
        lastIndex[s[i]] = i;
    }

    vector<int> res;
    int size = 0, end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        size++;
        end = max(end, lastIndex[s[i]]);

        if (i == end)
        {
            res.push_back(size);
            size = 0;
        }
    }
    return res;
}