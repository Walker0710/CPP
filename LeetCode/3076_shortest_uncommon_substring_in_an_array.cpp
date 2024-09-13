#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

vector<string> shortestSubstrings(vector<string> &arr)
{
    vector<set<string>> substringMap;
    for (auto str : arr)
    {
        set<string> substringsSet;
        for (int i = 0; i < str.size(); i++)
        {
            string currentSubstr = "";
            for (int j = i; j < str.size(); j++)
            {
                currentSubstr += str[j];
                substringsSet.insert(currentSubstr);
            }
        }
        substringMap.push_back(substringsSet);
    }
    vector<string> result(arr.size(), "");
    for (int i = 0; i < substringMap.size(); i++)
    {
        for (auto it = substringMap[i].begin(); it != substringMap[i].end(); it++)
        {
            bool found = true;
            string currentSubstr = *it;
            for (int j = 0; j < substringMap.size(); j++)
            {
                if (j != i)
                {
                    if (substringMap[j].count(currentSubstr) == 1)
                    {
                        found = false;
                        break;
                    }
                }
            }
            if (found == true)
            {
                if (result[i] != "" && (result[i].size() <= currentSubstr.size() && result[i] < currentSubstr))
                {
                }
                else
                {
                    result[i] = currentSubstr;
                }
            }
        }
    }
    return result;
}

vector<string> shortestSubstrings(vector<string> &arr)
{
    int n = arr.size();
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        bool notfound = false;
        string res;
        for (int k = 1; k <= arr[i].size(); k++)
        {
            for (int j = 0; j <= arr[i].size() - k; j++)
            {
                string t = arr[i].substr(j, k);
                bool flag = false;
                for (int l = 0; l < n; l++)
                {
                    if (l != i && arr[l].find(t) != string::npos)
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    if (res.empty() || res > t)
                        res = t;
                    notfound = true;
                }
            }
            if (notfound)
                break;
        }
        ans.push_back(res);
    }
    return ans;
}