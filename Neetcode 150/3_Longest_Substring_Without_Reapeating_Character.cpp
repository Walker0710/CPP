#include <bits/stdc++.h>

using namespace std;

// << ,

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    
    int len = 0;
    int last = 0;
    unordered_set<char> set1;

    for(int i = 0; i<n; i++) {
        if(set1.find(s[i]) == set1.end()) {
            set1.insert(s[i]);
            len = max(len, static_cast<int>(set1.size()));
        }

        else {
            while(set1.find(s[i]) != set1.end()) {
                set1.erase(s[last]);
                last++;
            }
            set1.insert(s[i]);
        }
    }

    return len;
}

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        // If the character has been seen and is inside the current window
        if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= start) {
            start = lastIndex[currentChar] + 1;  // move start right after the last occurrence
        }

        lastIndex[currentChar] = end;  // update the last seen index
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}