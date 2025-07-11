#include <bits/stdc++.h>

using namespace std;

// << ,

int findPermutationDifference(string s, string t)
{
    unordered_map<int, vector<int>> mp;

    for(int i = 0; i<s.length(); i++) {
        mp[s[i]].push_back(i);
        mp[t[i]].push_back(i);
    }

    int ans = 0;

    for(auto &yoo : mp) {
        ans = ans + abs(yoo.second[0] - yoo.second[1]);
    }

    return ans;
}