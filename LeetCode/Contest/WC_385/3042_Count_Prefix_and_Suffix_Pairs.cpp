#include <bits/stdc++.h>

using namespace std;

// << ,

bool isCheck(string s1, string s2)
{
    int len = s2.length();
    int len2 = s1.length();

    for (int i = 0; i < len2; i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }

        if (s1[i] != s2[len - len2 + i])
        {
            return false;
        }
    }

    return true;
}

int countPrefixSuffixPairs(vector<string> &words)
{
    int n = words.size();

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (words[i].length() <= words[j].length() && isCheck(words[i], words[j]))
            {
                cnt++;
            }
        }
    }

    return cnt;
}