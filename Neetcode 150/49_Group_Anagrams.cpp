#include <bits/stdc++.h>

using namespace std;

// << ,

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    
    unordered_map<string, vector<string>> rec;
    
    for(int i = 0; i<n; i++) {
        string s = strs[i];
        string sorted = strs[i];

        sort(sorted.begin(), sorted.end());

        rec[sorted].push_back(s);
    }

    vector<vector<string>> ans;

    for(auto yoo : rec) {
        ans.push_back(yoo.second);
    }

    return ans;
}