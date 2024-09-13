#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& arr, int key) {

    int start = 0;
    int end = arr.size() - 1;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}

int searchInsert(vector<int>& nums, int target) {

    int ans = binarySearch(nums, target);

    if(ans == -1) {

        if(nums[0] > target) {

            return 0;
        }

        if(nums[nums.size() - 1] < target) {

            return nums.size();
        }

        int s = 0;
        int e = nums.size() - 1;

        int mid = (s+e)/2;

        while(e>s) {

            if(nums[mid] > target && nums[mid-1] < target) {

                return mid;
            }

            if(nums[mid] < target && nums[mid + 1] > target) {

                return mid+1;
            }

            if(nums[mid] > target) {

                e = mid -1;
            }

            if(nums[mid] < target) {

                s = mid + 1;
            }

            mid = (s+e)/2;
        }
    }

    else {

        return ans;
    }
}

