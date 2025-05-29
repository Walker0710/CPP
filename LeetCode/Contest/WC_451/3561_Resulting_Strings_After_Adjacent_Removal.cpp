#include <bits/stdc++.h>

using namespace std;

// << ,

string resultingString(string s) {
    string result;

    for (char c : s) {
        if (!result.empty()) {
            char top = result.back();
            int diff = abs(c - top);
            if (diff == 1 || diff == 25) {
                result.pop_back(); 
                continue;
            }
        }
        result.push_back(c); 
    }

    return result;
}

string resultingString(string s)
{
    bool changed = true;
    string res = s;

    while (changed)
    {
        changed = false;
        
        for (int i = 0; i < res.length() - 1; ++i)
        {
            int diff = abs(res[i] - res[i + 1]);
            
            if (diff == 1 || diff == 25)
            {
                res = res.substr(0, i) + res.substr(i + 2);
                changed = true;
                break;
            }
        }
    }

    return res;
}