#include <bits/stdc++.h>

using namespace std;

// << ,

// rec only

int dfs(vector<int> &nums)
{
    if (nums.size() == 2)
    return 0;

    int maxCoins = 0;
    
    for (int i = 1; i < nums.size() - 1; i++)
    {
        int coins = nums[i - 1] * nums[i] * nums[i + 1];
    
        vector<int> newNums = nums;
        newNums.erase(newNums.begin() + i);
    
        coins += dfs(newNums);
    
        maxCoins = max(maxCoins, coins);
    }
    
    return maxCoins;
}

int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    return dfs(nums);
}


// rec + mem
