#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int max_len = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                max_len = max(max_len, i - st.top());
            }
        }
    }

    return max_len;
}