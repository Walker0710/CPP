#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumDifference(vector<int> &nums, int k)
{
    unordered_set<int> st1, st2;

    for (int i = 0; i < nums.size(); i++)
    {
        unordered_set<int> curr;
        curr.insert(nums[i]);

        for (int val : st2)
        {
            curr.insert(val | nums[i]);
        }

        for (auto x : st2)
        {
            st1.insert(x);
        }

        st2 = curr;
    }

    for (auto x : st2)
    st1.insert(x);

    int mini = INT_MAX;
    
    for (auto x : st1)
    {
        mini = min(mini, abs(k - x));
    }

    return mini;
}