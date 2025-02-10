#include <bits/stdc++.h>

using namespace std;

// << ,

int minFlips (string s)
{
    int n = s.length();
    int case1 = 0;
    int case2 = 0;

    //case 1 = 1
    for(int i = 0; i<n; i++) {
        if(i%2 == 0) {
            if(s[i] == '0') {
                case1++;
            }
        }

        else {
            if(s[i] == '1') {
                case1++;
            }
        }
    }

    //case 2 = 0
    for(int i = 0; i<n; i++) {
        if(i%2 == 0) {
            if(s[i] == '1') {
                case2++;
            }
        }

        else {
            if(s[i] == '0') {
                case2++;
            }
        }
    }

    return min(case1, case2);
}