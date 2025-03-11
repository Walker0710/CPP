#include <bits/stdc++.h>

using namespace std;

// << ,

string rearrangeString(string &s)
{
    int n = s.length();
    int mxCnt = 0;
    char ch = '#';

    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;

        if (freq[s[i]] > mxCnt)
        {
            mxCnt = freq[s[i]];
            ch = s[i];
        }
    }

    if (mxCnt > ((n + 1) / 2))
        return "";

    int ind = 0;
    while (mxCnt > 0)
    {
        s[ind] = ch;
        ind = ind + 2;
        mxCnt--;
    }
    freq[ch] = 0;

    for (char ch = 'a'; ch <= 'z'; ch++)
    {

        while (freq[ch] > 0)
        {

            ind = (ind >= n) ? 1 : ind;
            s[ind] = ch;
            ind += 2;
            freq[ch]--;
        }
    }

    return s;
}