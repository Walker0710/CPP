#include <bits/stdc++.h>

using namespace std;

// << ,

int scoreOfString(string s)
{
    int ans = 0;

    for(int i = 0; i<s.length()-1; i++) {
        ans += abs(s[i] - s[i + 1]);
    }

    return ans;
}