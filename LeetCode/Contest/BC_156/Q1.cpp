#include <bits/stdc++.h>

using namespace std;

// << ,

int maxFreqSum(string s)
{
    vector<int> freq(26, 0);

    for(int i = 0; i<s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    int maxVowel = 0;
    int maxConsonant = 0;

    for(int i = 0; i<26; i++) {
        if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
            maxVowel = max(maxVowel, freq[i]);
        }

        else {
            maxConsonant = max(maxConsonant, freq[i]);
        }
    }

    return maxVowel + maxConsonant;
}