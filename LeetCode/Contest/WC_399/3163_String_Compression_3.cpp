#include <bits/stdc++.h>

using namespace std;

// << ,

string compressedString(string word)
{
    string ans = "";
    int i = 0;
    int n = word.length();

    while (i < n)
    {
        int cnt = 0;
        char ch = word[i];

        while (i < n && word[i] == ch && cnt < 9)
        {
            cnt++;
            i++;
        }

        ans += to_string(cnt) + ch;
    }

    return ans;
}
