#include <bits/stdc++.h>

using namespace std;

// << ,

// Rec only
int solve(int index, int space, vector<int> &arr, int k)
{

    if (index == arr.size())
    {
        return 0;
    }

    // includeing
    int inc = INT_MAX;

    if ((space == k) || (arr[index] <= space))
        inc = solve(index + 1, space - arr[index] - 1, arr, k);

    // exclude
    int exc = INT_MAX;

    if (space != k)
        exc = (space + 1) * (space + 1) + solve(index, k, arr, k);

    int ans = min(inc, exc);

    return ans;
}

int solveWordWrap(vector<int> arr, int k)
{
    return solve(1, k - arr[0] - 1, arr, k);
}

// Meme + Rec
int solveMem(int index, int space, vector<int> &arr, int k, vector<vector<int>> &dp)
{

    if (index == arr.size())
    {
        return 0;
    }

    if (dp[index][space] != -1)
    {
        return dp[index][space];
    }

    // includeing
    int inc = INT_MAX;

    if ((space == k) || (arr[index] <= space))
        inc = solveMem(index + 1, space - arr[index] - 1, arr, k, dp);

    // exclude
    int exc = INT_MAX;

    if (space != k)
        exc = (space + 1) * (space + 1) + solveMem(index, k, arr, k, dp);

    int ans = min(inc, exc);

    return dp[index][space] = ans;
}

int solveWordWrap(vector<int> arr, int k)
{
    vector<vector<int>> dp(arr.size() + 1, vector<int>(k, -1));

    int yoo = solveMem(1, k - arr[0] - 1, arr, k, dp);

    return yoo;
}

/// yoo
vector<vector<int>>dp;

int helper(int curr,int spaces,vector<int>&nums,int &k){
    if(curr==nums.size()){
        return 0;
    }
    
    if(dp[curr][spaces]!=-1){
        return dp[curr][spaces];
    }
    
    int a = INT_MAX;
    int newSpaces = spaces+1+nums[curr];
    if(newSpaces<=k){
        a = helper(curr+1,newSpaces,nums,k);
    }

    int b = helper(curr+1,nums[curr],nums,k) + (k-spaces)*(k-spaces);

    return dp[curr][spaces] = min(a,b);
}

int solveWordWrap(vector<int>nums, int k) 
{ 
    int n = nums.size();
    dp.resize(n+1,vector<int>(k+1,-1));
    return helper(1,nums[0],nums,k);
} 