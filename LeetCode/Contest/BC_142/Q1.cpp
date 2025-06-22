#include <bits/stdc++.h>

using namespace std;

// << ,

int possibleStringCount(string word)
{
    int count = 1, n = word.length();
    for (int i = 1; i < n; ++i)
    {
        if (word[i] == word[i - 1])
            ++count;
    }
    return count;
}