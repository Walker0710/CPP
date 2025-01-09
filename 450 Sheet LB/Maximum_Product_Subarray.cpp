#include <bits/stdc++.h>

using namespace std;

// << ,

int maxProduct(vector<int> &arr)
{
    int pre = 1;
    int suf = 1;
    int ans = INT_MIN;
    int n = arr.size();

    for(int i = 0; i<n; i++) {

        if(pre == 0) 
        pre = 1;

        if(suf == 0) 
        suf = 1;
        
        pre = pre*arr[i];
        suf = suf*arr[n-i-1];

        ans = max(ans, max(pre, suf));
    }

    return ans;
}