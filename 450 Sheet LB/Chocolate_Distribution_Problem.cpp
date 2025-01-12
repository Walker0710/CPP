#include <bits/stdc++.h>

using namespace std;

// << ,

int findMinDiff(vector<int> &a, int m)
{
    sort(a.begin(), a.end());
    int ans = INT_MAX;

    for(int i = 0; i+m-1<n; i++) {
        ans = min(a[m+i-1] - a[i], ans);
    }

    return ans;
}