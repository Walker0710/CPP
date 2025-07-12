#include <bits/stdc++.h>

using namespace std;

// << ,

bool canJump(vector<int> &nums)
{
    int goal = nums.size() - 1;

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (i + nums[i] >= goal)
        {
            goal = i;
        }
    }

    return goal == 0;
}

bool canJump(vector<int> &nums)
{
    int maxReach = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > maxReach)
        return false;
        
        maxReach = max(maxReach, i + nums[i]);
    }
    
    return true;
}