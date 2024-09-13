#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &nums) {

    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i<n; i++) {

        int curr = max(prev1, prev2 + nums[i]);

        prev2 = prev1;
        prev1 = curr;
    } 

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse) {

    int n = valueInHouse.size();

    if(n == 1) 
    return valueInHouse[0];

    vector<int> first, second;

    for(int i = 0; i<n; i++) {

        if(i != n-1)
        first.push_back(valueInHouse[i]);

        if(i != 0)
        second.push_back(valueInHouse[i]);
    }

    return max(solve(first), solve(second));
}