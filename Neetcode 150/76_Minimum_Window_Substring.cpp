#include <bits/stdc++.h>

using namespace std;

// << ,

string minWindow(string s, string t) {
    unordered_map<char, int> countT, window;
    
    for(int i = 0; i<t.length(); i++) {
        countT[t[i]]++;
    }

    int have = 0;
    int need = countT.size();

    pair<int, int> resPair = {-1, -1};
    int resLen = INT_MAX;
    int start = 0;

    for(int i = 0; i<s.length(); i++) {
        char c = s[i];
        window[c]++;

        if(countT.count(c) && countT[c] == window[c]) {
            have++;
        }

        while(have == need) {
            
            if(i - start + 1 < resLen) {
                resLen = i - start + 1;
                resPair = {start, i};
            }

            window[s[start]]--;

            if(countT.count(s[start]) && countT[s[start]] > window[s[start]]) {
                have--;
            }

            start++;
        }
    }

    return resLen == INT_MAX ? "" : s.substr(resPair.first, resLen);
}