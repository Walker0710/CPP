#include <bits/stdc++.h>

using namespace std;

// << ,

string minimizeStringValue(string s)
{
    map<char, int> mp;

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        mp[ch] = 0;
    }

    int n = s.length();
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (ch == '?')
        {
            cahr minChar = 'a';
            int minFreq = INT_MAX;

            for (auto it : mp)
            {
                if (it.second < minFreq)
                {
                    minChar = it.first;
                    minFreq = it.second;
                }
            }

            mp[minChar]++;
            ans = ans + minChar;
        }

        else
        {
            mp[ch]++;
            ans = ans + ch;
        }
    }

    return ans;
}

string minimizeStringValue(string s)
{
    vector<int> freq(26, 0);
    string temp = "";

    for (auto c : s)
    {
        if (c != '?')
        freq[c - 'a']++;
    }

    for (auto ind = 0; ind < s.size(); ++ind)
    {
        if (s[ind] != '?')
        continue;

        int minFreqInd = 0, minFreq = INT_MAX;

        for (int i = 0; i < 26; ++i)
        {
            if (minFreq > freq[i])
            {
                minFreq = freq[i];
                minFreqInd = i;
            }
        }

        temp += ('a' + minFreqInd);
        freq[minFreqInd]++;
    }

    sort(temp.begin(), temp.end());

    for (int i = 0, j = 0; i < s.size(); ++i)
    {
        if (s[i] == '?')
        s[i] = temp[j++];
    }
    
    return s;
}