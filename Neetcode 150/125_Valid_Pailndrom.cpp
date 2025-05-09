#include <bits/stdc++.h>

using namespace std;

// << ,

bool isPalindrome(string s)
{
    string t;
    
    for (const auto &a : s)
    {
        if (a >= 'A' && a <= 'Z')
        {
            t.push_back(a - 'A' + 'a');
        }
        else if (a >= 'a' && a <= 'z')
        {
            t.push_back(a);
        }
        else if (a >= '0' && a <= '9')
        {
            t.push_back(a);
        }
    }
    
    int len = t.size();
    
    for (int i = 0; i < len / 2; ++i)
    {
        if (t[i] != t[len - i - 1])
        {
            return false;
        }
    }
    return true;
}