#include <bits/stdc++.h>

using namespace std;

// << ,

int sumOfEncryptedInt(vector<int> &nums)
{
    int ans = 0;
 
    for (int i = 0, n = nums.size(); i < n; ++i)
    {
        int sub = nums[i], ones = 0, maxi = 0, t = 0;

        while (sub)
        {
            maxi = max(maxi, sub % 10);
            sub /= 10;
            ++ones;
        }
        
        while (ones--)
        t = t * 10 + maxi;
    
        ans += t;
    }
 
    return ans;
}