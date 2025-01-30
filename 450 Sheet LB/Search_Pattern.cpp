#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> search(string pattern, string text)
{
    int i = 0;
    int j = 0;

    vector<int> ans;

    while (i < text.length())
    {
        int cnt = 0;

        if (pattern[j] != text[i])
            i++;

        while (i < text.length() && j < pattern.length() && text[i] == pattern[j])
        {
            cnt++;
            i++;
            j++;
        }

        if (cnt == pattern.size())
        {
            ans.push_back(i - pattern.length() + 1);
        }

        else
        {
            j = 0;
        }
    }

    return ans;
}

vector<int> search(string pattern, string text)
{
    vector<int> ans;
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++)
    {
        if (text.substr(i, m) == pattern)
        {
            ans.push_back(i);
        }
    }

    return ans;
}
