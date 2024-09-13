#include<iostream>
#include<vector>

using namespace std;

bool fullysorted(vector<int>& nums) {

    for(int i = 0; i<nums.size() - 1; i++) {

        if(nums[i] > nums[i+1]) {

            return false;
        }
    }

    return true;
}

int findMin(vector<int>& nums) {

    if(fullysorted(nums)) {

        return nums[0];
    }

    else {

    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(nums[mid] >= nums[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return nums[s];

    }
}


//2nd approch chat gpt

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}