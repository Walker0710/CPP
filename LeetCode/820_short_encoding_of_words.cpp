#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>

using namespace std;

int minimumLengthEncoding(vector<string>& words) {
    unordered_map<string, int> map;

    for(auto i:words) {
        map[i]++;
    }

    for(auto word:words) {
        for(int i = 1; i<word.length(); i++) {
            if(map.count(word.substr(i, word.length() - 1))) {
                map[word.substr(i)] = 0;
            }
        }
    }

    int ans = 0;
    for(auto i:map) {
        if(i.second)
        ans = ans + i.first.length() + 1;
    }
    return ans;
}