#include <bits/stdc++.h>

using namespace std;

// << ,
bool bs(const vector<int> &a, int target)
{
    int s = 0, e = a.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (a[mid] == target)
        {
            return true;
        }
        else if (a[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return false;
}

vector<vector<int>> getPairs(vector<int> &a)
{
    vector<vector<int>> ans;

    bool flag = count(a.begin(), a.end(), 0) > 1;

    sort(a.begin(), a.end());

    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= 0)
            break;

        int yoo = a[i];

        if (bs(a, -yoo))
            ans.push_back({yoo, -yoo});
    }

    if (flag)
    {
        ans.push_back({0, 0});
    }

    return ans;
}