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



static bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    return a[1] > b[1];

    return a[0] < b[0];
}

int numberOfPairs(vector<vector<int>> &v)
{
    int n = v.size();
    sort(v.begin(), v.end(), comp);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        int x1 = v[i][0];
        int y1 = v[i][1];
        long long k = -10000000000;

        for (int j = i + 1; j < n; j++)
        {
            int x2 = v[j][0];
            int y2 = v[j][1];

            if (y2 > y1)
                continue;

            if (y2 > k)
                ans++;

            if (y2 > k)
                k = y2;
        }
    }

    return ans;
}










int getId(int ele, vector<int> &arr)
{
    return lower_bound(arr.begin(), arr.end(), ele) - arr.begin();
}

int rectangleArea(vector<vector<int>> &rectangles)
{
    set<int> x_set, y_set;

    for (auto &it : rectangles)
    {
        x_set.insert(it[0]);
        y_set.insert(it[1]);
        x_set.insert(it[2]);
        y_set.insert(it[3]);
    }

    vector<int> x(x_set.begin(), x_set.end());
    vector<int> y(y_set.begin(), y_set.end());

    vector<vector<int>> taken(401, vector<int>(401, 0));
    long long ans = 0, MOD = 1e9 + 7;

    for (auto &v : rectangles)
    {
        for (int i = getId(v[0], x); i < getId(v[2], x); i++)
        {
            for (int j = getId(v[1], y); j < getId(v[3], y); j++)
            {

                if (taken[i][j])
                    continue;

                taken[i][j] = 1;
                long long len = x[i + 1] - x[i];
                long long breath = y[j + 1] - y[j];

                ans += ((len % MOD) * (breath % MOD)) % MOD;
                ans %= MOD;
            }
        }
    }

    return ans;
}