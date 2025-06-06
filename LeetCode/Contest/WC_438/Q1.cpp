#include <bits/stdc++.h>

using namespace std;

// << ,

bool hasSameDigits(string s)
{
    string s1;
    while (s.size() != 2)
    {
        s1 = "";
        for (int i = 0; i < s.size() - 1; i++)
        {
            s1 += (s[i] + s[i + 1]) % 10;
        }
        s = s1;
    }
    return s1[0] == s1[1];
}