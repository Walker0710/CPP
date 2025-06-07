#include <bits/stdc++.h>

using namespace std;

// << ,

int sumOfGoodNumbers(vector<int> &nums, int k)
{
    int sum  = 0;
    int n = nums.size();

    for(int i = 0; i<n; i++) {
        bool yoo = true;

        if(i - k >= 0 && nums[i] <= nums[i-k]) {
            yoo = false;
        }

        if(i + k < n && nums[i] <= nums[i+k]) {
            yoo = false;
        }

        if(yoo)
        sum = sum + nums[i];
    }

    return sum;
}