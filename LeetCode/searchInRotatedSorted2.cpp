#include<iostream>
#include<vector>

using namespace std;

bool AllSame(vector<int>& arr, int s, int e) {

    for(int i = s; i<= e; i++) {

        if(arr[i] != arr[i+1]) {

            return false;
        }
    }

    return true;
}

int getPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

bool binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return true;
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
    
    return false;
}

bool search(vector<int>& nums, int target) {

    int pivot = getPivot(nums, nums.size());

    if( target >= nums[pivot] && target <= nums[nums.size() - 1])
    {//BS on second line
        return binarySearch(nums, pivot, nums.size() - 1, target);
    }
    else
    {//BS on first line
        return binarySearch(nums, 0, pivot - 1, target);
    } 
}



//just aase he 

class Solution {

    private: 

    int getPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

bool binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return true;
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
    
    return false;
}

public:
    bool search(vector<int>& nums, int target) {

    int pivot = getPivot(nums, nums.size());

    if( target >= nums[pivot] && target <= nums[nums.size() - 1])
    {//BS on second line
        return binarySearch(nums, pivot, nums.size() - 1, target);
    }
    else
    {//BS on first line
        return binarySearch(nums, 0, pivot - 1, target);
    }   
    }
};