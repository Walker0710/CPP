#include <bits/stdc++.h>

using namespace std;

// << ,

bool isPossibleToSplit(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> st1;
    unordered_set<int> st2;

    for (int i = 0; i < n; i++)
    {
        int el = nums[i];

        if (st1.find(el) != st1.end())
        {

            if (st2.find(el) != st2.end())
            {
                return false;
            }

            else
            {
                st2.insert(el);
            }
        }

        else
        {
            st1.insert(el);
        }
    }
    return true;
}