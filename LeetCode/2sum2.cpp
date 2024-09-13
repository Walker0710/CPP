#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    int s = 0; 
    int e = nums.size()-1;

    vector<int> ans;

    while(e>s) {

        if(nums[s] + nums[e] == target) {

            ans.push_back(s);
            ans.push_back(e);
            break;
        }

        else if (nums[s] + nums[e] > target) {

            e--;
        }

        else {

            s++;
        }
    }

    return ans;
}
