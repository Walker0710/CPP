#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]].push_back(i);
    }

    vector<int> ans;

    for (int i = 0; i < queries.size(); i++)
    {
        int ind = queries[i];

        vector<int> yoo = mp[nums[ind]];

        if (yoo.size() == 1)
            ans.push_back(-1);

        else
        {
            int mini = 0;

            for (int j = 0; j < yoo.size(); j++)
            {

                if (ind == yoo[j])
                {

                    if (j == 0)
                    {
                        mini = min(yoo[j + 1] - yoo[j], yoo[j] + (n - yoo[yoo.size() - 1]));
                    }

                    else if (j == yoo.size() - 1)
                    {
                        mini = min(yoo[j] - yoo[j - 1], yoo[0] + (n - yoo[j]));
                    }

                    else
                    {
                        mini = min(yoo[j + 1] - yoo[j], yoo[j] - yoo[j - 1]);
                    }

                    break;
                }
            }

            ans.push_back(mini);
        }
    }

    return ans;
}

vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
{
    int n = queries.size(), sz = nums.size();
    unordered_map<int, vector<int>> indices;
   
    for (int i = 0; i < nums.size(); i++)
    {
        indices[nums[i]].push_back(i);
    }
   
    for (auto &pair : indices)
    {
        auto arr = pair.second;
        int m = arr.size();
    
        if (m == 1)
        {
            nums[arr[0]] = -1;
            continue;
        }
    
        for (int i = 0; i < m; i++)
        {
            int f = arr[(i + 1) % m], b = arr[(i - 1 + m) % m];
            int forward = min(sz - arr[i] + f, abs(arr[i] - f));
            int backward = min(abs(b - arr[i]), arr[i] + sz - b);
            nums[arr[i]] = min(backward, forward);
        }
    }
    
    for (int i = 0; i < n; i++)
    queries[i] = nums[queries[i]];
    
    return queries;
}