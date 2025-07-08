#include <bits/stdc++.h>

using namespace std;

// << ,

#define MOD 1000000007

int valueAfterKSeconds(int n, int k)
{
    vector<int> pre(n, 1);

    while (k--)
    {
        for (int i = 1; i < n; i++) {
            pre[i] = (pre[i] + pre[i - 1]) % MOD;
        }
    }

    return pre[n - 1];
}
