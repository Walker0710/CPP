#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1st approch
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    for(int i = 0; i<n; i++) {

        nums1[m+i] = nums2[i];
    }

    sort(nums1.begin(), nums1.end());
}

//2nd approch
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int i = m - 1; // Pointer for nums1
    int j = n - 1; // Pointer for nums2
    int k = m + n - 1; // Pointer for the merged array

    // Merge nums1 and nums2 from the end
    while (i >= 0 && j >= 0) {

        if (nums1[i] > nums2[j]) {

            nums1[k--] = nums1[i--];
        }
        
        else {

            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, copy them to nums1
    while (j >= 0) {

        nums1[k--] = nums2[j--];
    }

    while (i >= 0) {

        nums1[k--] = nums1[i--];
    }
}


