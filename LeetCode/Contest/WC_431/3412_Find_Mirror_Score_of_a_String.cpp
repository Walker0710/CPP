#include <bits/stdc++.h>

using namespace std;

// << ,

long long calculateScore(string s)
{
    vector<stack<int>> rec(26);
    long long ans = 0;

    for (int i = 0; i < s.length(); i++)
    {

        if (!rec[25 - (s[i] - 'a')].empty())
        {
            int prev = rec[25 - (s[i] - 'a')].top();
            rec[25 - (s[i] - 'a')].pop();

            ans = ans + (i - prev);
        }

        else
        {
            rec[s[i] - 'a'].push(i);
        }
    }

    return ans;
}