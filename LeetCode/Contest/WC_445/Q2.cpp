#include <bits/stdc++.h>

using namespace std;

// << ,

string solve(int cnt, int i)
{
    char c = i + 'a';

    string ans = "";

    for (int i = 0; i < cnt; i++)
    {
        ans = ans + c;
    }

    return ans;
}

string smallestPalindrome(string s)
{
    vector<int> cnt(26, 0);

    for (int i = 0; i < s.length(); i++)
    {
        cnt[s[i] - 'a']++;
    }

    string ans;

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            int yoo = cnt[i];

            string toAdd = solve(yoo, i);
            ans = ans + toAdd;
        }
    }

    for (int i = 25; i >= 0; i--)
    {
        if (cnt[i] % 2 == 0)
        {
            int yoo = cnt[i] / 2;

            string toAdd = solve(yoo, i);
            ans = toAdd + ans + toAdd;
        }
    }

    return ans;
}

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