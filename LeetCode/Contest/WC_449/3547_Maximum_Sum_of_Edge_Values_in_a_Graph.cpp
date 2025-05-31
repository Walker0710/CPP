#include <bits/stdc++.h>

using namespace std;

// << ,

long long maxScore(int n, vector<vector<int>> &edges)
{
    long long res = (n == edges.size()) ? 2 : 0;

    for (int i = 1; i < n - 1; ++i)
    {
        res += static_cast<long long>(i) * (i + 2);
    }

    res += static_cast<long long>(n) * (n - 1);
    return res;
}