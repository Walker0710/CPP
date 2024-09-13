#include<iostream>
#include<vector>

using namespace std;

//1st approch
void sortColors(vector<int>& nums) {

    for(int i = 0; i<nums.size(); i++) {

        for(int j = i+1; j<nums.size(); j++) {

            if(nums[j] == 0 && nums[i] == 2 || nums[j] == 0 && nums[i] == 1 || nums[j] == 1 && nums[i] == 2) {

                swap(nums[j], nums[i]);
            }
        }
    }
}

//2nd approch
void sortColors(vector<int>& nums) {
    int p0 = 0, curr = 0, p2 = nums.size() - 1;

    while (curr <= p2) {
        
        if (nums[curr] == 0) {
            
            swap(nums[curr], nums[p0]);
            curr++;
            p0++;
        }
        
        else if (nums[curr] == 2) {
            
            swap(nums[curr], nums[p2]);   // dhyan rhkna yha pe curr++ nhi h
            p2--;
        }
        
        else {
            curr++;
        }
    }
}

