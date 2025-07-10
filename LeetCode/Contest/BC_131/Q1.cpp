#include <bits/stdc++.h>

using namespace std;

// << ,

int duplicateNumbersXOR(vector<int> &nums)
{
    int n = nums.size();
    vector<int> yoo(51, 0);

    for(int i = 0; i<n; i++) {
        yoo[nums[i]]++;
    }

    int ans = 0;

    for(int i = 0; i<51; i++) {
        if(yoo[i] == 2)
        ans = ans^i;
    }

    return ans;
}