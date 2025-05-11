#include <bits/stdc++.h>

using namespace std;

// << ,

bool checkInclusion(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    if(n > m)
    return false;
    
    vector<int> rec(256, 0);
    vector<int> window(256, 0);

    for(int i = 0; i<n; i++) {
        rec[s1[i]]++;
        window[s2[i]]++;
    }

    if(rec == window) {
        return true;
    }

    for(int i = n; i<m; i++) {
        window[s2[i]]++;
        window[s2[i-n]]--;

        if(rec == window)
        return true;
    }

    return false;
}