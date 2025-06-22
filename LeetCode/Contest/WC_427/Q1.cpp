#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> constructTransformedArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++)
    {
        int k = nums[i];
        int ind = ((i + ((k % n) + n)) % n); // Normalize movement for circular array

        res[i] = nums[ind];
    }

    return res;
}