#include <bits/stdc++.h>

using namespace std;

// << ,


//accepted one

vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    vector<long long> ans(n, 0);

    vector<pair<int, int>> rec;
    for (int i = 0; i < n; ++i)
    {
        rec.emplace_back(nums1[i], i);
    }

    sort(rec.begin(), rec.end());

    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long heapSum = 0;
    int j = 0;

    for (int i = 0; i < n; ++i)
    {
        int val = rec[i].first;
        int idx = rec[i].second;

        while (j < n && rec[j].first < val)
        {
            int v = nums2[rec[j].second];

            if ((int)minHeap.size() < k)
            {
                minHeap.push(v);
                heapSum += v;
            }

            else if (!minHeap.empty() && v > minHeap.top())
            {
                heapSum -= minHeap.top();
                minHeap.pop();
                minHeap.push(v);
                heapSum += v;
            }
            ++j;
        }

        ans[idx] = heapSum;
    }

    return ans;
}


// tle 
vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    vector<long long> ans(n, 0);

    vector<pair<int, int>> rec;
    for (int i = 0; i < n; ++i)
    {
        rec.emplace_back(nums1[i], i);
    }

    sort(rec.begin(), rec.end());

    multiset<int> active;

    int j = 0;

    for (int i = 0; i < n; ++i)
    {
        int val = rec[i].first;
        int idx = rec[i].second;

        while (j < n && rec[j].first < val)
        {
            active.insert(nums2[rec[j].second]);
            ++j;
        }

        long long sum = 0;
        auto it = active.rbegin();
        for (int cnt = 0; cnt < k && it != active.rend(); ++cnt, ++it)
        {
            sum += *it;
        }

        ans[idx] = sum;
    }

    return ans;
}