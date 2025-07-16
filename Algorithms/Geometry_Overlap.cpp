#include <bits/stdc++.h>

using namespace std;

// << ,

long long largestSquareArea(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
{
    long long ans = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = i + 1; j < nums1.size(); j++)
        {
            long long mini_x = max(nums1[i][0], nums1[j][0]);
            long long maxi_x = min(nums2[i][0], nums2[j][0]);
            long long mini_y = max(nums1[i][1], nums1[j][1]);
            long long maxi_y = min(nums2[i][1], nums2[j][1]);

            if (mini_x < maxi_x && mini_y < maxi_y)
            {

                long long s = min(maxi_x - mini_x, maxi_y - mini_y);
                ans = max(ans, s * s);
            }
        }
    }

    return ans;
}