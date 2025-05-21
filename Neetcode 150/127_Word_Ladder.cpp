#include <bits/stdc++.h>

using namespace std;

// << ,

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> words(wordList.begin(), wordList.end());

    int res = 0;
    queue<string> q;
    q.push(beginWord);

    while(!q.empty()) {
        
        res++;
        int len = q.size();

        for(int i = 0; i<len; i++) {
            string yoo = q.front();
            q.pop();

            if(yoo == endWord)
            return res;

            for(int j = 0; j<yoo.size(); j++) {
                char ch = yoo[j];

                for(char c = 'a'; c <= 'z'; c++) {

                    if(c == ch)
                    continue;

                    yoo[j] = c;

                    if(words.find(yoo) != words.end()) {
                        q.push(yoo);
                        words.erase(yoo);
                    }
                }

                yoo[j] = ch; 
            }
        }
    }
    return 0;
}