#include <bits/stdc++.h>

using namespace std;

// << ,

vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int m = queries.size();
    vector<bool> visi(n, false);

    long long total = accumulate(nums.begin(), nums.end(), 0LL);
    int cnt = n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({nums[i], i});
    }

    vector<long long> ans(m);

    for (int i = 0; i < m; i++)
    {
        int ind = queries[i][0];
        int k = min(queries[i][1], cnt);

        if (!visi[ind])
        {
            visi[ind] = true;
            total = total - nums[ind];
        }

        while (k && !pq.empty())
        {
            pair<int, int> topp = pq.top();
            pq.pop();

            if (!visi[topp.second])
            {
                visi[topp.second] = true;
                total = total - topp.first;
                k--;
                cnt--;
            }
        }

        ans[i] = total;
    }

    return ans;
}