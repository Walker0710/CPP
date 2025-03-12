#include <bits/stdc++.h>

using namespace std;

// << ,

string removeConsecutiveCharacter(string& s) {
    int n = s.length();
    if (n == 0) return ""; 

    char lastInc = s[0];
    string ans(1, s[0]); 

    for (int i = 1; i < n; i++) {
        if (s[i] != lastInc) {
            lastInc = s[i];
            ans += s[i]; 
        }
    }

    return ans;
}