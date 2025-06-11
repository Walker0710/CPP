#include <bits/stdc++.h>

using namespace std;

// << ,

long long minCost(vector<int> &arr, vector<int> &brr, long long k)
{
    int n = arr.size();

    long long cost_no_rearrange = 0;

    for (int i = 0; i < n; i++)
    {
        cost_no_rearrange += abs(arr[i] - brr[i]);
    }

    vector<int> a_sorted = arr;
    vector<int> b_sorted = brr;

    sort(a_sorted.begin(), a_sorted.end());
    sort(b_sorted.begin(), b_sorted.end());

    long long cost_rearrange = k;

    for (int i = 0; i < n; i++)
    {
        cost_rearrange += abs(a_sorted[i] - b_sorted[i]);
    }

    return min(cost_no_rearrange, cost_rearrange);
}