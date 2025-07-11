#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> grayCode(int n)
{
    vector<int> ans(1, 0); // Start with 0 (base case for 0-bit Gray code)
 
    for (int i = 0; i < n; i++)
    {
        // For each bit position i, reflect and set bit i
        for (int j = ans.size() - 1; j >= 0; j--)
        {
            ans.push_back(ans[j] | (1 << i)); // Set bit i in the reflected values
        }
    }

    return ans;
}
