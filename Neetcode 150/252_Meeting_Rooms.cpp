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

bool canAttendMeetings(vector<Interval> &intervals)
{
    int n = intervals.size();

    if (n <= 1)
        return true;

    sort(intervals.begin(), intervals.end(),
         [](const Interval &a, const Interval &b)
         { return a.end < b.end; });

    Interval prev = intervals[0];

    for (int i = 1; i < n; ++i)
    {
        if (intervals[i].start < prev.end)
        {
            return false; 
        }
        else
        {
            prev = intervals[i]; 
        }
    }

    return true;
}