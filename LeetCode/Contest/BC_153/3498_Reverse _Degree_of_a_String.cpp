#include <bits/stdc++.h>

using namespace std;

// << ,

int reverseDegree(const string& s)
{
    int ans = 0;

    for (int i = 0; i < s.length(); i++) {
        int reversePos = 26 - (s[i] - 'a'); // Reverse position in alphabet
        ans += (i + 1) * reversePos;
    }

    return ans;
}