#include <bits/stdc++.h>

using namespace std;

// << ,

bool check(vector<int> pos, int x, vector<int> &nums1, vector<int> & nums2)
{
    int p = 0;
    
    for (int i = 0; i < nums2.size(); i++)
    {
        while ((p == pos[0] || p == pos[1]) && p < nums1.size())
        {
            p++;
        }
        if (p >= nums1.size() || nums2[i] - nums1[p] != x)
        {
            return false;
        }
        p++;
    }
    
    return true;
}

int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int n = nums2.size();
    int n1_sum = accumulate(nums1.begin(), nums1.end(), 0);
    int n2_sum = accumulate(nums2.begin(), nums2.end(), 0);

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = i + 1; j < nums1.size(); j++)
        {
            int total = n2_sum - n1_sum + nums1[i] + nums1[j]; 
            
            if (total % n == 0)
            { 
                int x = total / n;
            
                if (check({i, j}, x, nums1, nums2))
                {
                    return x;
                }
            }
        }
    }

    return -1;
}