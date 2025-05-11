#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>

using namespace std;

// first approch
string minWindow(string s, string t)
{
    unordered_map<char, int> rec;

    for (int i = 0; i < t.length(); i++)
        rec[t[i]]++;

    string ans = "";

    for (int i = 0; i + t.length() <= s.length(); i++)
    {
        unordered_map<char, int> count;
        int len = t.length() + i;

        for (int j = 0; j < len; j++)
        {
            count[s[j]]++;
        }

        for (int j = 0; j + len < s.length(); j++)
        {
            bool flag = true;

            if (j != 0)
            {
                count[s[j - 1]]--;
                count[s[j + len - 1]]++;
            }

            for (int z = 0; z < t.length(); z++)
            {
                if ((count.find(t[z]) == count.end()) || (rec[t[z]] > count[t[z]]))
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                for (int p = j; p < j + len; p++)
                {
                    ans = ans + s[p];
                }
                return ans;
            }
        }
    }
    return ans;
}

// 2nd approch
string minWindow(string s, string t)
{
    if (s.empty() || t.empty() || s.length() < t.length())
    {
        return "";
    }

    vector<int> map(128, 0);
    int count = t.length();
    int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
    for (char c : t)
    {
        map[c]++;
    }

    while (end < s.length())
    {
        if (map[s[end++]]-- > 0)
        {
            count--;
        }

        while (count == 0)
        {
            if (end - start < minLen)
            {
                startIndex = start;
                minLen = end - start;
            }

            if (map[s[start++]]++ == 0)
            {
                count++;
            }
        }
    }

    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}


string minWindow(string s, string t)
{
    if (t.empty())
        return "";

    unordered_map<char, int> countT, window;
    
    for (char c : t)
    {
        countT[c]++;
    }

    int have = 0, need = countT.size();
    pair<int, int> res = {-1, -1};
    int resLen = INT_MAX;
    int l = 0;

    for (int r = 0; r < s.length(); r++)
    {
        char c = s[r];
        window[c]++;

        if (countT.count(c) && window[c] == countT[c])
        {
            have++;
        }

        while (have == need)
        {
            if ((r - l + 1) < resLen)
            {
                resLen = r - l + 1;
                res = {l, r};
            }

            window[s[l]]--;
            if (countT.count(s[l]) && window[s[l]] < countT[s[l]])
            {
                have--;
            }
            l++;
        }
    }

    return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
}