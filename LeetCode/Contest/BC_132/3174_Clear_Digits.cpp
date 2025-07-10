#include <bits/stdc++.h>

using namespace std;

// << ,

string clearDigits(string s)
{
    string stack;
 
    for (char c : s)
    {
        if (isdigit(c))
        {
            if (!stack.empty())
                stack.pop_back();
        }
 
        else
        {
            stack.push_back(c);
        }
    }
    return stack;
}