#include <bits/stdc++.h>

using namespace std;

// << ,

int characterReplacement(string s, int k)
{
    int ans = 0;
    unordered_set<char> st(s.begin(), s.end());

    for(auto c : st) {
        int l = 0;
        int cnt = 0;

        for(int r = 0; r<s.length(); r++) {
            if(s[r] == c) {
                cnt++;
            }

            while ((r-l+1) - cnt > k) 
            {
                if(s[l] == c)
                cnt--;

                l++;
            }

            ans = max(ans, r-l+1);
        }
    }

    return ans;
}