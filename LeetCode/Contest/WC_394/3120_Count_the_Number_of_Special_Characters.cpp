#include <bits/stdc++.h>

using namespace std;

// << ,

int numberOfSpecialChars(string word)
{
    unordered_set<int> upper;
    unordered_set<int> lower;
    unordered_set<char> done;
    
    int ans = 0;

    for(int i = 0; i<word.length(); i++) {

        if(done.find(word[i]) != done.end()) {
            continue;
        }

        if(word[i] >= 'a' && word[i] <= 'z') {
            if(upper.find(word[i] - 'a') != upper.end()) {
                ans++;

                done.insert(word[i]);
            }

            else {
                lower.insert(word[i] - 'a');
            }
        }

        if(word[i] >= 'A' && word[i] <= 'Z') {
            if(lower.find(word[i] - 'A') != lower.end()) {
                ans++;

                done.insert(word[i]);
            }

            else {
                upper.insert(word[i] - 'A');
            }
        }
    }

    return ans;
}