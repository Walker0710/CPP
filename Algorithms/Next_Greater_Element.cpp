#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(temperatures.size(), 0);

    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        int curr = temperatures[i];

        while (s.top() != -1 && temperatures[i] >= temperatures[s.top()])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    for (int i = 0; i < temperatures.size(); i++)
    {
        if (ans[i] != -1)
        {
            ans[i] = ans[i] - i;
        }

        else
        {
            ans[i] = 0;
        }
    }

    return ans;
}