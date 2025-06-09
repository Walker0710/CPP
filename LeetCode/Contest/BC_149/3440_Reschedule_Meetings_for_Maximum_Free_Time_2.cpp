#include <bits/stdc++.h>

using namespace std;

// << ,

int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
{
    int ans = 0, n = startTime.size();

    map<int, int> m;
    m[startTime[0]]++;
    m[eventTime - endTime.back()]++;

    for (int i = 1; i < n; i++)
        m[startTime[i] - endTime[i - 1]]++;

    for (int i = 0; i < n; i++)
    {
        int width = endTime[i] - startTime[i];
        int prev = i > 0 ? endTime[i - 1] : 0;
        int next = i < n - 1 ? startTime[i + 1] : eventTime;

        bool canPlace = false;

        int gap1 = startTime[i] - prev;
        int gap2 = next - endTime[i];

        m[gap1]--;
        m[gap2]--;

        if (m[gap1] <= 0)
            m.erase(gap1);
        if (m[gap2] <= 0)
            m.erase(gap2);

        if ((*m.rbegin()).first >= width)
            canPlace = true;

        m[gap1]++;
        m[gap2]++;

        if (canPlace)
            ans = max(ans, next - prev);
        else
            ans = max(ans, next - prev - width);
    }

    return ans;
}