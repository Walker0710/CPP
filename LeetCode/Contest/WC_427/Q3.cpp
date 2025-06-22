#include <bits/stdc++.h>

using namespace std;

// << ,

long long maxSubarraySum(vector<int> &nums, int k)
{
    vector<long long> ps(1);
 
    for (int n : nums)
        ps.push_back(ps.back() + n);
 
    long long res = LLONG_MIN;
    
    for (int p = 0; p < k; ++p)
    {
        long long sum = 0;
    
        for (int i = p; i + k <= nums.size(); i += k)
        {
            long long n = ps[i + k] - ps[i];
            sum = max(n, sum + n);
            res = max(res, sum);
        }
    }
    
    return res;
}