#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> resultArray(vector<int> &nums)
{
    int n = nums.size();

    vector<int> arr1;
    vector<int> arr2;

    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);

    for (int i = 2; i < n; i++)
    {
        if (arr1.back() > arr2.back())
        {
            arr1.push_back(nums[i]);
        }
        else
        {
            arr2.push_back(nums[i]);
        }
    }

    vector<int> ans;

    for (int x : arr1)
    ans.push_back(x);
    
    for (int x : arr2)
    ans.push_back(x);

    return ans;
}