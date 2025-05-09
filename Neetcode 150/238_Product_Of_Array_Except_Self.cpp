#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int index = 0;

    for(int i = 0; i<n; i++) {
        if(nums[i] == 0) {
            index = i;
            count++;
        }
    }

    vector<int> ans(n, 0);

    if(count == 0) {
        int product = 1;

        for(int i = 0; i<n; i++) {
            product = product*nums[i];
        }

        for(int i = 0; i<n; i++) {
            ans[i] = product/nums[i];
        }
    }

    else if (count == 1) {
        int product = 1;

        for(int i = 0; i<n; i++) {
            if(i != index) {
                product = product*nums[i];
            }
        }

        ans[index] = product;
    }

    return ans;
}