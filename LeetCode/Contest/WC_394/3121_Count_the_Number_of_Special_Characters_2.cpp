#include <bits/stdc++.h>

using namespace std;

// << ,

int numberOfSpecialChars(string word)
{
    unordered_map<int, int> mp;
    vector<bool> visi(26, false);

    for (int i = 0; i < word.length(); i++)
    {
        char ch = word[i];

        if (ch >= 'a' && ch <= 'z')
        {
            mp[ch - 'a'] = i;
        }
    }

    int ans = 0;

    for (int i = 0; i < word.length(); i++)
    {
        char ch = word[i];

        if(ch >= 'A' && ch <= 'Z' && !visi[ch - 'A']) {

            visi[ch - 'A'] = true;

            if(mp[ch - 'A'] < i) {
                ans++;
            }
        }
    }

    return ans;
}




int numberOfSpecialChars(string word)
{
    vector<int> lower(26, -1); 
    vector<int> upper(26, -1); 

    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        if (ch >= 'a' && ch <= 'z')
        {
            lower[ch - 'a'] = i;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            if (upper[ch - 'A'] == -1)
                upper[ch - 'A'] = i;
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i])
        {
            ans++;
        }
    }

    return ans;
}
