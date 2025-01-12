#include <bits/stdc++.h>

using namespace std;

// << ,

int minSwap(vector<int> &a, int k)
{
    int n = a.size();
    int cnt = 0;

    for(int i = 0; i<n; i++) {
        if(a[i] <= k) {
            cnt++;
        }
    }

    int cnt_wdw = 0;
\
    for(int i = 0; i<cnt; i++) {
        if(a[i] <= k) {
            cnt_wdw++;
        }
    }

    int ans = cnt - cnt_wdw;

    for(int i = cnt; i<n; i++) {
        if(a[i] <= k) {
            cnt_wdw++;
        }

        if(a[i-cnt] <= k) {
            cnt_wdw--;
        }

        ans = min(ans, cnt - cnt_wdw);
    }
    return ans;
}