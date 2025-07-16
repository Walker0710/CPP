#include <bits/stdc++.h>

using namespace std;

// << ,

vector<string> shortestSubstrings(vector<string> &arr)
{
    int n = arr.size();
    unordered_map<string, int> mpp;

    for (int idx = 0; idx < n; idx++)
    {
        unordered_set<string> seenInThisString;
        string &it = arr[idx];

        for (int i = 0; i < it.size(); i++)
        {
            string subset = "";

            for (int j = i; j < it.size(); j++)
            {
                subset += it[j];
                seenInThisString.insert(subset);
            }
        }

        for (const auto &s : seenInThisString)
        {
            mpp[s]++;
        }
    }

    vector<string> ans;

    for (int idx = 0; idx < n; idx++)
    {
        string &it = arr[idx];
        string smallest = "";

        for (int i = 0; i < it.size(); i++)
        {
            string subset = "";

            for (int j = i; j < it.size(); j++)
            {
                subset += it[j];

                if (mpp[subset] == 1)
                {
                    if (smallest == "" || subset.size() < smallest.size() || (subset.size() == smallest.size() && subset < smallest))
                    {
                        smallest = subset;
                    }
                }
            }
        }

        ans.push_back(smallest);
    }

    return ans;
}