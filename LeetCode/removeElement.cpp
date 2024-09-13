#include<iostream>
#include<vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {

    int p1 = 0;
    int p2 = nums.size() - 1;

    while(p2 > p1) {

        while(nums[p1] != val && p1 < p2) {

            p1++;
        }

        while(nums[p2] == val && p1 < p2) {

            p2--;
        }

        swap(nums[p1], nums[p2]);
        p1++;
        p2--;
    }

    int size = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] != val) {

            size++;
        }
    }

    return size;
}