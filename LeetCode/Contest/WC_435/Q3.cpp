#include <bits/stdc++.h>

using namespace std;

// << ,

int maxDifference(string s, int k)
{
    vector<int> freq(4, 0);

    for(int i = 0; i<k; i++) {
        freq[s[i] - '1']++;
    }

    
}