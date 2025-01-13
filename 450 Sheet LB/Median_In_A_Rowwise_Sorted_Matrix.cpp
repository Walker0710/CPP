#include <bits/stdc++.h>

using namespace std;

// << ,

int median(vector<vector<int>> &mat)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    int n = mat.size();
    int m = mat[0].size();

    int ans = 0;

    for(int i = 0; i<n; i++) {
        mini = min(mini, mat[i][0]);
        maxi = max(maxi, mat[i][m-1]);
    }

    while(mini <= maxi) {
        int mid = (maxi + mini)/2;

        int freq = 0;

        for(int i = 0; i<n; i++) {
            freq = freq + upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }

        if(freq >= (n*m + 1)/2) {
            ans = mid;
            maxi = mid - 1;
        }

        else {
            mini = mid+1;
        }
    }

    return ans;
}