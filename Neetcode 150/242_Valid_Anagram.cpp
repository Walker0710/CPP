#include <bits/stdc++.h>

using namespace std;

// << ,

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

    int n = s.length();
    
    vector<int> s1(256, 0);
    vector<int> s2(256, 0);

    for(int i = 0; i<n; i++) {
        s1[s[i]]++;
        s2[t[i]]++;
    }

    for(int i = 0; i<256; i++) {
        if(s1[i] != s2[i]) {
            return false;
        }
    }

    return true;
}