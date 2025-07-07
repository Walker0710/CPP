#include <bits/stdc++.h>

using namespace std;

// << ,

int maxOperations(string s)
{
    int one = 0;
    int ans = 0;
    int n = s.length();

    for(int i = 0; i<n-1; i++) {
        if(s[i] == '1' && s[i+1] == '0') {
            one++;
            ans = ans + one;
        }

        else if(s[i] == '1')
        one++;
    }

    return ans;
}