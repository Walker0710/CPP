#include <bits/stdc++.h>

using namespace std;

// << ,

bool isPossibleToRearrange(string s, string t, int k)
{
    int n = s.length();
    int len = n / k;
    unordered_map<string, int> mp_s, mp_t;

    for (int i = 0; i < n; i += len)
    mp_s[s.substr(i, len)]++;

    for (int i = 0; i < n; i += len)
    mp_t[t.substr(i, len)]++;

    return mp_s == mp_t;
}