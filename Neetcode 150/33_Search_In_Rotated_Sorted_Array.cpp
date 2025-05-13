#include <bits/stdc++.h>

using namespace std;

// << ,

int findMin(vector<int>& nums) {
    int s = 0;
    int e = nums.size() - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] > nums[e]) {
            s = mid + 1; 
        } else {
            e = mid; 
        }
    }

    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        if(key > arr[mid]) {
            start = mid + 1;
        }

        else { 
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();

    int piv = findMin(nums);

    if(target >= nums[piv] && target <= nums[n-1]) {
        return binarySearch(nums, piv, n-1, target);
    }

    else {
        return binarySearch(nums, 0, piv -1, target);
    }
}