#include <bits/stdc++.h>

using namespace std;

// << ,

bool hasSpecialSubstring(string s, int k) {
    int n = s.length();
    
    for (int i = 0; i + k <= n; i++) {
        string st = s.substr(i, k);
        char ch = st[0];
        
        // Check if all characters in the substring are the same
        bool allSame = true;
        for (int j = 1; j < k; j++) {
            if (st[j] != ch) {
                allSame = false;
                break;
            }
        }
        
        if (!allSame)
            continue;

        // Check surrounding characters
        bool leftOK = (i == 0 || s[i - 1] != ch);
        bool rightOK = (i + k == n || s[i + k] != ch);
        
        if (leftOK && rightOK)
            return true;
    }
    
    return false;
}
