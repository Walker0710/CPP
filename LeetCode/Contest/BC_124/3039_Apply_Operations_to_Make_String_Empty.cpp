#include <bits/stdc++.h>

using namespace std;

// << ,

string lastNonEmptyString(string s)
{
    unordered_map<char, int> mp;

    int maxii = 0;

    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;

        if (mp[s[i]] > maxii)
        {
            maxii = mp[s[i]];
        }
    }

    string ans = "";
    unordered_set<char> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (mp[s[i]] == maxii && st.find(s[i]) == st.end())
        {
            ans = s[i] + ans;
            st.insert(s[i]);
        }
    }

    return ans;
}