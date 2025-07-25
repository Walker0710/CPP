#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<int> &ans) {

    if(index >= nums.size()) {

        ans.push_back(output);
        return ;
    }

    //exclude
    solve(nums, output, index+1, ans);

    //include

    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);
}

vector<vector<int>> subset(vector<int> & nums) {

    vector<vector<int>> ans;
    vector<int> output;

    int index = 0;
    solve(nums, output, index, ans);

    return ans;
}

