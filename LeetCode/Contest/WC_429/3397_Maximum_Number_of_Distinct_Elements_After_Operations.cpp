#include <bits/stdc++.h>

using namespace std;

// << ,

int maxDistinctElements(vector<int> &nums, int k)
{
    int n = nums.size();

    if (n == 1)
        return 1;

    sort(nums.begin(), nums.end());

    int prev = nums[0] - k;

    for (int i = 1; i < n; i++)
    {
        int yoo = nums[i] - prev - 1;
        yoo = max(yoo, -k);
        yoo = min(yoo, k);

        nums[i] = nums[i] - yoo;
        prev = nums[i];
    }

    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }

    return st.size();
}


int maxDistinctElements(vector<int> &nums, int k)
{
    int ans = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0, last = INT_MIN; i < nums.size(); ++i)
    {
        int mn = nums[i] - k;
        int mx = nums[i] + k;

        if (last < mn)
        {
            last = mn;
            ans++;
        }

        else if (last < mx)
        {
            last = last + 1;
            ans++;
        }
    }

    return ans;
}