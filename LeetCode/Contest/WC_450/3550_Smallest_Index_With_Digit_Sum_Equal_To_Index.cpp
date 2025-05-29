#include <bits/stdc++.h>

using namespace std;

// << ,

bool check(int yoo, int i) {
    int ans = 0;

    while (yoo != 0)
    {
        ans = ans + yoo%10;
        yoo = yoo/10;
    }

    return ans == i;    
}

int smallestIndex(vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i<n; i++) {
        if(check(nums[i], i)) {
            return i;
        }
    }

    return -1;
}