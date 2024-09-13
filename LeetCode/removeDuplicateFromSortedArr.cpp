#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {

    int p1 = 0;
    int p2 = 1;
    int size = 1;
    vector<int> index;

    while(p2 < nums.size()) {

        if(nums[p1] == nums[p2]) {

            index.push_back(p2);
        }

        else{

            size++;
        }

        p1++;
        p2++;
    }

    for(int i = 0; i<index.size(); i++) {

        nums[index[i]] = 101;
    }

    sort(nums.begin(), nums.end());

    return size;
}

//2nd approch chat gpt

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int k = 1; // Initialize k to 1 for the first element

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            // Update the array in-place by keeping unique elements
            nums[k++] = nums[i];
        }
    }

    return k;
}