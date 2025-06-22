#include <bits/stdc++.h>

using namespace std;

// << ,

vector<string> stringSequence(string target)
{
    vector<string> ans;
    string st = "";

    for(int i = 0; i<target.length(); i++) {
        
        char ch = 'a';

        while (ch != target[i])
        {
            ans.push_back(st + ch);
            ch++;
        }

        st = st + ch;        
        ans.push_back(st);
    }

    return ans;
}