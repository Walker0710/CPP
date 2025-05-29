#include <bits/stdc++.h>

using namespace std;

// << ,

int maxSubstrings(string word)
{
    int i = 0;
    int n = word.length();
    int ans = 0;

    vector<vector<int>> rec(26);

    while(i < n) {
        int c = word[i];
        rec[c - 'a'].push_back(i);
        
        if(rec[c - 'a'].size() >= 2 && rec[c-'a'].back() - rec[c-'a'][0] >= 3) {
            ans++;
            rec = vector<vector<int>>(26);
        }

        i++;
    }

    return ans;
}