#include <bits/stdc++.h>

using namespace std;

// << ,

int subarraySum(vector<int> &arr, int target)
{

    int n = arr.size();
    int s = 0, e = 0, sum = 0;
    int ans = 0;

    if(n == 1) {
        return arr[0] == target;
    }

    while (e < n)
    {
        sum += arr[e];

        while (sum > target && s <= e)
        {
            sum -= arr[s];
            s++;
        }

        if (sum == target)
        {
            ans++;
        }

        e++;
    }

    return ans;
}