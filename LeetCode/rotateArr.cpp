#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

//1st approch
void rotate(vector<int>& nums, int k) {

    int x = k%nums.size();
    while(x>0) {

        int y = nums[nums.size() - 1];
        nums.pop_back();
        nums.insert(nums.begin(), y);
        x--;
    }
}

//2nd approch
void rotate(vector<int>& nums, int k) {

    vector<int> ans(nums.size());
    for(int i = 0; i<nums.size(); i++) {

        int x = nums.size() - k%nums.size() + i;
        ans[i] = nums[x%nums.size()];
    }

    for(int i = 0; i<nums.size() ; i++) {

        nums[i] = ans[i];
    }
}

//3rd approch (wtf)
void rotate(vector<int>& nums, int k) {

        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
}

