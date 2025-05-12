#include <bits/stdc++.h>

using namespace std;

// << ,

int evalRPN(vector<string> &tokens)
{
    stack<int> st;

    for (string &s : tokens)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            int p = st.top();
            st.pop();
            int q = st.top();
            st.pop();
            int result;

            if (s == "+")
                result = q + p;
            else if (s == "-")
                result = q - p;
            else if (s == "*")
                result = q * p;
            else
                result = q / p;

            st.push(result);
        }
        else
        {
            st.push(stoi(s));
        }
    }

    return st.top();
}