#include <bits/stdc++.h>

using namespace std;

// << ,

string getEncryptedString(string s, int k)
{
    string ans;
    int n = s.length();

    for(int i = 0; i<s.length(); i++) {
        int j = (i+k)%n;

        ans = ans + s[j]; 
    }

    return ans;
}