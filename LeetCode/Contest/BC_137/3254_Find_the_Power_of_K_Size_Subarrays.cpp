#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> resultsArray(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> yoo(n);

    int l = 0;

    for(int r = 1; r<n; r++) {
        if(nums[r] == nums[r-1] + 1) {
            yoo[r] = l;
        }

        else {
            l = r;
            yoo[r] = l;
        }
    }

    vector<int> ans(n-k+1);

    for(int i = 0; i<n-k+1; i++) {
        if(yoo[i + k - 1] > yoo[i]) {
            ans[i] = -1;
        }

        else {
            ans[i] = nums[i + k - 1];
        }
    }

    return ans;
}