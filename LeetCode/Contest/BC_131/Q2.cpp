#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x)
{
    vector<int> rec;

    for(int i = 0; i<nums.size(); i++) {
        if(nums[i]==x) {
            rec.push_back(i);
        }
    }

    vector<int> ans(queries.size(), -1);

    for(int i = 0; i<queries.size(); i++) {
        if(queries[i] <= rec.size()) {
            ans[i] = rec[queries[i] - 1];
        }
    }

    return ans;
} 