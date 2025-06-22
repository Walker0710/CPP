#include <bits/stdc++.h>

using namespace std;

// << ,

int yoo(int n) {
    int sum = 0;

    while (n)
    {
        sum = sum + n%10;
        n = n/10;
    }

    return sum;    
}

int minElement(vector<int> &nums)
{
    int mini = INT_MAX;

    for(int i = 0; i<nums.size(); i++) {
        mini = min(mini, yoo(nums[i]));
    }

    return mini;
}