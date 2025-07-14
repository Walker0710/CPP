#include <bits/stdc++.h>

using namespace std;

// << ,

long long countSubstrings(string s, char c)
{
    long long cnt = 0;

    for(int i = 0; i<s.length(); i++) {
        if(s[i] == c)
        cnt++;
    }

    return (1LL*cnt*(cnt + 1))/2;
}