#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int solve(int index, int diff, int A[]) {

    if(index < 0)
    return 0;

    int ans = 0;

    for(int j = index - 1; j>=0; j--) {

        if(A[index] - A[j] == diff) {

            ans = max(ans, 1 + solve(j, diff, A));
        }
    }
    return ans;
}

int lengthOfLongestAP(int A[], int n) {

    if(n <= 2)
    return n;

    int ans = 0;

    for(int i = 0; i<n; i++) {

        for(int j = i+1; j<n; j++) {

            ans = max(ans, 2 + solve(i, A[j] - A[i], A));
        }
    }

    return ans;
}

int solve(int index, int diff, vector<int> &nums) {

    if(index < 0)
    return 0;

    int ans = 0;

    for(int j = index - 1; j>=0; j--) {

        if(nums[index] - nums[j] == diff) {
            ans = max(ans, 1 + solve(j, diff, nums));
        }
    }

    return 2+ans;
}

int numberOfArithmeticSlices(vector<int>& nums) {

    if(nums.size() <= 2)
    return 0;

    int ans = 0;

    for(int i = 1; i<nums.size(); i++) {

        for(int j = i+1; j<nums.size(); j++) {

            int size = solve(i, nums[j]-nums[i], nums);

            if(size >= 3) 
            ans = ans + size - 2;
        }
    }
    return ans;
}