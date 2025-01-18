#include <bits/stdc++.h>

using namespace std;

// << ,

int maxSubStr(string str)
{
    int one= 0;
    int zero = 0;
    int ans = 0;

    for(int i = 0; i<str.length(); i++) {
        if(str[i] == '0')
        zero++;

        else 
        one++;

        if(one == zero) {
            ans++;
            zero = 0;
            one = 0;
        }
    }

    return ans;
}