#include <bits/stdc++.h>

using namespace std;

// << ,

string findValidPair(string s)
{
    vector<int> freq(10, 0);

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - '0']++;
    }

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] != s[i] &&
            freq[s[i] - '0'] == s[i] - '0' &&
            freq[s[i - 1] - '0'] == s[i - 1] - '0')
        {

            string res = "";
            res += s[i - 1];
            res += s[i];
            return res;
        }
    }

    return "";
}