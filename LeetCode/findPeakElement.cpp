#include<iostream>
#include<vector>

using namespace std;

int findPeakElement(vector<int>& nums) {

    int s = 0;
    int e = nums.size() - 1;

    int mid = (e+s)/2;

    while(e>s) {

        if(nums[mid+1] > nums[mid]) {

            s = mid + 1;
        }

        if(nums[mid+1] < nums[mid]) {

            e = mid;
        }

        mid = (s+e)/2;
    }

    return s;
}