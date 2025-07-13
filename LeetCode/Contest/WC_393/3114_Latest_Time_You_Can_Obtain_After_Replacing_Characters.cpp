#include <bits/stdc++.h>

using namespace std;

// << ,

string findLatestTime(string s)
{
    if(s[0] == '?') {
        if(s[1] == '?') {
            s[1] = '1';
            s[0] = '1';
        }

        else {
            if(s[1] == '1' || s[1] == '0') {
                s[0] = '1';
            }

            else {
                s[0] = '0';
            }
        }
    }

    else if(s[1] == '?') {
        if(s[0] == '0') {
            s[1] = '9';
        }

        else {
            s[1] = '1';
        }
    }

    if(s[3] == '?') {
        if(s[4] == '?') {
            s[3] = '5';
            s[4] = '9';
        }

        else {
            s[3] = '5';
        }
    }

    else if(s[4] == '?') {
        s[4] = '9';
    }

    return s;
}