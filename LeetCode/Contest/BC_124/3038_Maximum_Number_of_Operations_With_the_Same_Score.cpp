#include <bits/stdc++.h>

using namespace std;

// << ,

int maxOperations(vector<int> &nums)
{
    int cnt = 1;
    int sum = nums[0] + nums[1];

    for (int i = 2; i < nums.size() - 1 && nums[i] + nums[i + 1] == sum; i += 2)
    {
        cnt++;
    }

    return cnt;
}