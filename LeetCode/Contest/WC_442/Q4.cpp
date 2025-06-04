#include <bits/stdc++.h>

using namespace std;

// << ,

long long minOperations(vector<vector<int>> &queries)
{
    long long ans = 0;

    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];

        for (int j = r; j >= l; j -= 2)
        {
            ans += floor(log2(j) / 2) + 1;
        }
    }

    return ans;
}