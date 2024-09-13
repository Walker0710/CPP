#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    vector<int> mergedArr;

    int i = 0;
    int j = 0;

    while(i<nums1.size() && j<nums2.size()) {

        if(nums1[i] < nums2[j]) {

            mergedArr.push_back(nums1[i]);
            i++;
        }

        else {

            mergedArr.push_back(nums2[j]);
            j++;
        }
    }

    while(i<nums1.size()) {

        mergedArr.push_back(nums1[i]);
        i++;
    }

    while(j<nums2.size()) {

        mergedArr.push_back(nums2[j]);
        j++;
    }

    int size = mergedArr.size();

    if(mergedArr.size()%2 == 1) {

        return mergedArr[size/2];
    }

    else {

        int yo = mergedArr[size/2] + mergedArr[size/2 - 1];

        return (double)yo/2;
    }
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    vector<int> ans;

    for(int i = 0; i<nums1.size(); i++) {

        ans.push_back(nums1[i]);
    }

    for(int i = 0; i<nums2.size(); i++) {

        ans.push_back(nums2[i]);
    }

    sort(ans.begin(), ans.end());

    int size = ans.size();

    if(ans.size()%2 == 1) {

        return ans[size/2];
    }

    else {

        int yo = ans[size/2] + ans[size/2 - 1];

        return (double)yo/2;
    }
}
