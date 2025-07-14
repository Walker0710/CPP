#include <bits/stdc++.h>

using namespace std;

// << ,

int cyclicDistance(char a, char b)
{
    int d = abs(a - b);
    return min(d, 26 - d);
}

string getSmallestString(string s, int k)
{
    string t = "";

    for (char ch : s)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            int dist = cyclicDistance(ch, c);
            if (dist <= k)
            {
                t += c;
                k -= dist;
                break;
            }
        }
    }

    return t;
}