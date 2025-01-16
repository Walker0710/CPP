#include <bits/stdc++.h>

using namespace std;

// << ,

int maxWater(vector<int> &height)
{
    int first = 0;
    int last = height.size() - 1;
    int maxarea = 0;
    while (first < last)
    {
        int currarea = min(height[first], height[last]) * (last - first);
        maxarea = max(maxarea, currarea);
        if (height[first] < height[last])
        {
            first++;
        }
        else
        {
            last--;
        }
    }
    return maxarea;
}