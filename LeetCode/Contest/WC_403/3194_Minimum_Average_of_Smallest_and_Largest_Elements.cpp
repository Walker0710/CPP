#include <bits/stdc++.h>

using namespace std;

// << ,

double minimumAverage(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    double mini = 51.0;

    for (int i = 0; i < n / 2; i++)
    {
        double avg = (nums[i] + nums[n - i - 1]) / 2.0;
        mini = min(mini, avg);
    }

    return mini;
}
