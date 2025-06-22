#include <bits/stdc++.h>

using namespace std;

// << ,

int minOperations(vector<int> &nums, int k)
{
    set<int> st(nums.begin(), nums.end());
    int cnt = 0;

    for (auto it = st.rbegin(); it != st.rend(); ++it) {
        if (*it > k)
            cnt++;

        if (*it < k)
            return -1;
    }

    return cnt;
}
