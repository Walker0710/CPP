#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

//rec only
int solve(vector<int> &stones, int index, int val)
{
    if (index == stones.size())
    {
        if (val < 0)
        return 1e9;
        
        return 0;
    }
    
    int pos = stones[index] + solve(stones, index + 1, val + stones[index]);
    int neg = -stones[index] + solve(stones, index + 1, val - stones[index]);
    return min(pos, neg);
}

int lastStoneWeightII(vector<int> &stones)
{
    return solve(stones, 0, 0);
}

//rec + mem
int solveMem(vector<int> &stones, int index, int val, vector<vector<int>> &dp) 
{
    if (index == stones.size())
    {
        if (val < 0)
        return 1e9;
        
        return 0;
    }

    if(dp[index][val] != -1)
    return dp[index][val];
    
    int pos = stones[index] + solveMem(stones, index + 1, val + stones[index], dp);
    int neg = -stones[index] + solveMem(stones, index + 1, val - stones[index], dp);
    return dp[index][val] = min(pos, neg);
}

int lastStoneWeightII(vector<int> &stones)
{
    vector<vector<int>> dp(stones.size()+1, vector<int> (6000, -1));
    return solveMem(stones, 0, 0, dp);
}
