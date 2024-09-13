#include<iostream>
#include<vector>

using namespace std;

int sum(vector<int>& nums, int s, int e) {

    int sum = 0;

    for(int i = s; i<=e; i++) {

        sum = sum + nums[i];
    }

    return sum;
}

int minSubArrayLen(int target, vector<int>& nums) {


}