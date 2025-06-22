#include <bits/stdc++.h>

using namespace std;

// << ,

long long yoo(unordered_map<long long, long long> &freq, int x)
{
    priority_queue<pair<long long, long long>> pq;

    for (const auto &entry : freq)
    {
        pq.push({entry.second, entry.first});
    }

    long long sum = 0;
    for (long long i = 0; i < x && !pq.empty(); i++)
    {
        auto top = pq.top();
        pq.pop();
        sum += top.second * top.first;
    }

    return sum;
}

vector<long long> findXSum(vector<int> &nums, int k, int x)
{
    vector<long long> ans;
    long long n = nums.size();

    unordered_map<long long, long long> freq;

    for (int i = 0; i < k; i++)
    {
        freq[nums[i]]++;
    }

    ans.push_back(yoo(freq, x));

    for (int i = 1; i + k <= n; i++)
    {
        freq[nums[i - 1]]--;

        if (freq[nums[i - 1]] == 0)
        {
            freq.erase(nums[i - 1]);
        }

        freq[nums[i + k - 1]]++;

        ans.push_back(yoo(freq, x));
    }

    return ans;
}