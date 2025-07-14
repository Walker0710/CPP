#include <bits/stdc++.h>

using namespace std;

// << ,

vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
{
    priority_queue<pair<long long, int>> pq;
    unordered_map<int, long long> mp;
    vector<long long> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] += freq[i];
        pq.push({mp[nums[i]], nums[i]});

        while (!pq.empty())
        {
            pair<long long, int> p = pq.top();

            if (mp[p.second] != p.first)
            pq.pop();
            
            else
            break;
        }
        
        ans.push_back(pq.top().first);
    }
    
    return ans;
}