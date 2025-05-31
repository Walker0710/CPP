#include <bits/stdc++.h>

using namespace std;

// << ,

int minDeletion(string s, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            pq.push(freq[i]); 
        }
    }

    int ans = 0;

    while (pq.size() > k) {
        ans += pq.top(); 
        pq.pop();
    }

    return ans;
}