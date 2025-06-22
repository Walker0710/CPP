#include <bits/stdc++.h>

using namespace std;

// << ,

string answerString(string word, int numFriends)
{
    if(numFriends == 1)
    return word;

    int k = word.length() - (numFriends - 1);
    string ans = "";

    for (int len = 1; len <= k; len++)
    {
        for (int i = 0; i <= word.length() - len; i++)
        {
            if (word.substr(i, len) > ans)
            {
                ans = sub;
            }
        }
    }

    return ans;
}

string answerString(string word, int numFriends)
{
    if (numFriends == 1)
        return word;

    string res = "";

    for (int i = 0; i < word.size(); i++)
        res = max(res, word.substr(i, word.length() - numFriends + 1));

    return res;
}