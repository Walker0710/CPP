#include <bits/stdc++.h>

using namespace std;

// << ,

int minOperations(int k)
{
    int ans = INT_MAX;

    for (int i = 0; i < k; i++)
    {
        int fir = 1 + i;               // start at 1 and increment i times
        int sec = (k + fir - 1) / fir; // ceil(k / fir)
        ans = min(ans, i + sec - 1);
    }

    return ans;
}