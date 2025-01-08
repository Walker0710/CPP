#include <bits/stdc++.h>

using namespace std;

// << ,

int longestConsecutive(vector<int> &arr)
{
    int n = arr.size();
    
    if(n == 0)
    return 0;

    int longest = 0;
    unordered_set<int> s;

    for(int i = 0; i<n; i++) {
        s.insert(arr[i]);
    }

    for(auto it : s) {
        if(s.find(it - 1) == s.end()) {
            int cnt = 1;
            int x = it;

            while(s.find(x+1) != s.end()) {
                cnt++;
                x++;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;
}