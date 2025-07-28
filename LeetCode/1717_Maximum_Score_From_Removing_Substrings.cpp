#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(string &s, char fir, char sec, int val)
{
    stack<char> st;

    int yoo = 0;

    for (char c : s)
    {
        if (!st.empty() && st.top() == fir && c == sec)
        {
            yoo = yoo + val;
            st.pop();
        }

        else
        {
            st.push(c);
        }
    }

    string temp;

    while (!st.empty())
    {
        temp.push_back(st.top());
        st.pop();
    }

    reverse(temp.begin(), temp.end());
    s = temp;

    return yoo;
}

int maximumGain(string s, int x, int y)
{
    int ans = 0;

    if (x > y)
    {
        ans = ans + solve(s, 'a', 'b', x);
        ans = ans + solve(s, 'b', 'a', y);
    }

    else
    {
        ans = ans + solve(s, 'b', 'a', y);
        ans = ans + solve(s, 'a', 'b', x);
    }

    return ans;
}