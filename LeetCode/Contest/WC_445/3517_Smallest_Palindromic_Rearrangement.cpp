#include <bits/stdc++.h>

using namespace std;

// << ,

string smallestPalindrome(string s)
{
    vector<int> cnt(26, 0);
    for (char ch : s)
        cnt[ch - 'a']++;

    string half = "", mid = "";

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            if (mid.empty())
            {
                mid = string(1, 'a' + i);
            }
            else
            {
                return ""; 
            }
        }

        half += string(cnt[i] / 2, 'a' + i);
    }

    string revHalf = half;
    reverse(revHalf.begin(), revHalf.end());

    return half + mid + revHalf;
}