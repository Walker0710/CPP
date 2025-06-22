#include <bits/stdc++.h>

using namespace std;

// << ,

bool reportSpam(vector<string> &message, vector<string> &bannedWords)
{
    unordered_set<string> yoo(bannedWords.begin(), bannedWords.end());

    int cnt = 0;

    for(int i = 0; i<message.size(); i++) {
        if(yoo.find(message[i]) != yoo.end()) {
            cnt++;

            if(cnt >= 2)
            return true;
        }
    }

    return false;
}