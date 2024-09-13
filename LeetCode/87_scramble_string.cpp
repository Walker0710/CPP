#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

unordered_map<string, bool> mp;

bool isScramble(string s1, string s2)
{

    if (s1 == s2)
        return true;

    string key = s1 + "*" + s2;

    if (mp.count(key))
        return mp[key];

    for (int i = 0; i < s1.size() - 1; i++)
    {
        if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(i + 1)))
        {
            return mp[key] = true;
        }

        if (isScramble(s1.substr(0, i + 1), s2.substr(s2.size() - i - 1)) && isScramble(s1.substr(i + 1), s2.substr(0, s2.size() - i - 1)))
        {
            return mp[key] = true;
        }
    }

    return mp[key] = false;
}