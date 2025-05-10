#include <bits/stdc++.h>

using namespace std;

// << ,

int maxArea(vector<int>& height) {
    int n = height.size();
    int s = 0;
    int e = n-1;
    int ans = 0;

    while(s < e) {
        ans = max(ans, (e-s)*min(height[s], height[e]));

        if(height[s] > height[e]) {
            e--;
        }

        else {
            s++;
        }
    }

    return ans;
}