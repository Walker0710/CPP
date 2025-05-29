#include <bits/stdc++.h>

using namespace std;

// << ,
long long minCuttingCost(int n, int m, int k)
{
    if (n <= k && m <= k)
    {
        return 0;
    }
    else if (n > k && m <= k)
    {
        return 1LL * k * (n - k);
    }
    else if (n <= k && m > k)
    {
        return 1LL * k * (m - k);
    }
    else
    {
        return 1LL * k * (m - k) + 1LL * k * (n - k);
    }
}
