#include <bits/stdc++.h>

using namespace std;

// << ,

int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
{
    sort(points.begin(), points.end());
    int n = points.size();

    int curr = 0;
    int i = 0;

    while (i < n)
    {
        int l = points[i][0];  
        while (i < n && points[i][0] <= l + w)
        {
            i++;
        }

        curr++;
    }

    return curr;
}