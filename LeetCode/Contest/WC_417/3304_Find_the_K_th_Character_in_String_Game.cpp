#include <bits/stdc++.h>

using namespace std;

// << ,

char kthCharacter(int k)
{
    string s = "a";

    while (s.length() < k)
    {
        string st = "";

        for (char c : s)
        {
            char next = (c == 'z') ? 'a' : c + 1;
            st += next;
        }
        s += st;
    }

    return s[k - 1];
}