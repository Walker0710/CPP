#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    priority_queue<pair<double, pair<int, int>>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            double frac = arr[i] / (arr[j] * 1.0);

            if (pq.size() == k)
            {
                if (frac < pq.top().first)
                {
                    pq.pop();
                    pq.push({frac, {arr[i], arr[j]}});
                }
            }

            else
            {
                pq.push({frac, {arr[i], arr[j]}});
            }
        }
    }

    pair<double, pair<int, int>> ans = pq.top();

    return {ans.second.first, ans.second.second};
}

// leetcode
vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    double l = 0, r = 1, n = arr.size();

    while (l < r)
    {
        double m = l + (r - l) / 2;
        int i = -1, x = 0, y = 1, count = 0;
        for (int j = 0; j < n; j++)
        {
            while (i + 1 < n && (double)arr[i + 1] < (double)m * arr[j])
                i++;
            if (i >= 0 && i < n)
            {
                count += i + 1;
                if (arr[i] * y > arr[j] * x)
                {
                    x = arr[i];
                    y = arr[j];
                }
            }
        }
        if (count == k)
        {
            return {x, y};
        }
        else if (count > k)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    return {};
}