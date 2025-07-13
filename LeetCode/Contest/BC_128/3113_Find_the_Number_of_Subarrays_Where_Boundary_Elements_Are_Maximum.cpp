#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(temperatures.size(), 0);

    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        int curr = temperatures[i];

        while (s.top() != -1 && temperatures[i] >= temperatures[s.top()])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

long long numberOfSubarrays(vector<int> &nums)
{
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]].push_back(i);
    }

    vector<int> nextt = dailyTemperatures(nums);
    int n = nums.size();
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (nextt[i] == -1)
            continue;

        int nex = nextt[i];
        int num = nums[i];

        const vector<int> &yoo = mp[num];

        auto it1 = lower_bound(yoo.begin(), yoo.end(), nex);
        auto it2 = upper_bound(yoo.begin(), yoo.end(), i);

        if (it1 != yoo.end() && it2 != yoo.end())
        {
            ans += (*it1 - *it2);
        }
    }

    return ans;
}



vector<int> prevGreater(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[i] > nums[s.top()])
        {
            result[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    return result;
}

long long numberOfSubarrays(vector<int> &nums)
{
    int n = nums.size();
    long long result = 0;

    vector<int> pGreater(prevGreater(nums));
    unordered_map<int, vector<int>> indices;

    for (int i = 0; i < n; i++)
    {
        auto &v = indices[nums[i]];
        v.push_back(i);

        result += v.end() - upper_bound(v.begin(), v.end(), pGreater[i]);
    }

    return result;
}