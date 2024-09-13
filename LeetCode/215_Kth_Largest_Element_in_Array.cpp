#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[largest] < arr[left]) {

        largest = left;
    }

    if(right < n && arr[largest] < arr[right]) {

        largest = right;
    } 

    if(largest != i) {

        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int findKthLargest(vector<int>& nums, int k) {

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i<k; i++) 
    minHeap.push(nums[i]);

    for(int i = k; i<nums.size(); i++) {

        if(nums[i] < minHeap.top()) {

            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    int ans = minHeap.top();
    return ans;
}