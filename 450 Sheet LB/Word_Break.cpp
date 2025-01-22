#include <bits/stdc++.h>

using namespace std;

// << ,
int solve(int index, const std::string &s, const std::unordered_set<std::string> &set) {
    
    if (index == s.length()) {
        return 1; 
    }

    for (int i = index; i < s.length(); i++) {

        if (set.find(s.substr(index, i - index + 1)) != set.end() && solve(i + 1, s, set)) {
            return 1;
        }
    }

    return 0; 
}

int wordBreak(int n, const std::string &s, const std::vector<std::string> &dictionary) {
    unordered_set<string> set(dictionary.begin(), dictionary.end());
    return solve(0, s, set);
}
