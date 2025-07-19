#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumArrayLength(vector<int> &nums)
{
    int mini = *min_element(nums.begin(), nums.end());
    int minCount = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == mini)
        minCount++;

        else if (nums[i] % mini != 0)
       return 1;
    }

    return (minCount + 1) / 2;
}