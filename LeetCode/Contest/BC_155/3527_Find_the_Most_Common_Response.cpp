#include <bits/stdc++.h>

using namespace std;

// << ,

string findCommonResponse(vector<vector<string>> &responses)
{
    unordered_map<string, int> mp;
    
    for (int i = 0; i < responses.size(); i++) {
        unordered_set<string> yoo(responses[i].begin(), responses[i].end());
        for (auto &it : yoo) {
            mp[it]++;
        }
    }

    string ans;
    int cnt = 0;

    for (auto &[st, freq] : mp) {
        if (freq > cnt || (freq == cnt && st < ans)) {
            ans = st;
            cnt = freq;
        }
    }

    return ans;
}
