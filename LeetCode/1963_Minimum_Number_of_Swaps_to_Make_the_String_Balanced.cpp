#include <bits/stdc++.h>

using namespace std;

// << ,

int minSwaps(string s)
{
    int close = 0;
    int maxClose = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '[')
        {
            close--;
        }
        else
        {
            close++;
        }

        maxClose = max(maxClose, close);
    }

    return (maxClose + 1) / 2;
}