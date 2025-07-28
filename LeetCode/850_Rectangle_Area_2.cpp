#include <bits/stdc++.h>

using namespace std;

// << ,

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