#include <bits/stdc++.h>

using namespace std;

// << ,

class Solution {
    public:
        string encode(vector<string>& strs) {
            string ans = "";
    
            for (const string& str : strs) {
                ans += to_string(str.length()) + "#" + str;
            }
    
            return ans;
        }
    
        vector<string> decode(string s) {
            vector<string> ans;
            int i = 0;
    
            while (i < s.length()) {
                
                int j = i;
                
                while (s[j] != '#') 
                j++;
                
                int len = stoi(s.substr(i, j - i));
                i = j + 1; 
                string str = s.substr(i, len);
                ans.push_back(str);
                i += len;
            }
    
            return ans;
        }
};