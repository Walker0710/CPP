#include <bits/stdc++.h>

using namespace std;

// << ,

class Interval
{
public:
    int start, end;

    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

int minMeetingRooms(vector<Interval> &intervals)
{
    map<int, int> mp;

    for(auto &i : intervals) {
        mp[i.start]++;
        mp[i.end]--;
    }

    int prev = 0;
    int res = 0;

    for(auto &[key, val] : mp) {
        prev = prev + val;
        res = max(res, prev);
    }

    return res;
}