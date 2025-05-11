#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    multiset<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.insert(nums[i]);
    }

    ans.push_back(*pq.rbegin()); // get max from the multiset

    for (int i = k; i < n; i++)
    {
        pq.insert(nums[i]);
        pq.erase(pq.find(nums[i - k])); // erase only one instance
        ans.push_back(*pq.rbegin());    // again, get max
    }

    return ans;
}

// This soln is something niceeee
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> output(n - k + 1);
    deque<int> q;
    int l = 0, r = 0;

    while (r < n)
    {
        while (!q.empty() && nums[q.back()] < nums[r])
        {
            q.pop_back();
        }
        q.push_back(r);

        if (l > q.front())
        {
            q.pop_front();
        }

        if ((r + 1) >= k)
        {
            output[l] = nums[q.front()];
            l++;
        }
        r++;
    }

    return output;
}