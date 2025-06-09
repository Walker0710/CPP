#include <bits/stdc++.h>

using namespace std;

// << ,

int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
{
    int n = startTime.size();
    vector<int> spaces;

    spaces.push_back(startTime[0] - 0);

    for (int i = 1; i < n; i++) {
        spaces.push_back(startTime[i] - endTime[i - 1]);
    }

    spaces.push_back(eventTime - endTime[n - 1]);

    int m = spaces.size();

    int windowSum = 0;

    for (int i = 0; i <= k && i < m; i++) {
        windowSum += spaces[i];
    }

    int ans = windowSum;

    for (int i = k + 1; i < m; i++) {
        windowSum += spaces[i];
        windowSum -= spaces[i - k - 1];
        ans = max(ans, windowSum);
    }

    return ans;
}
