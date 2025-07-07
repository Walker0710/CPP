#include <bits/stdc++.h>

using namespace std;

// << ,

string getSmallestString(string s)
{
    int i = 0;
    int n = s.length();

    while (i<n-1)
    {
        if(s[i]%2 == s[i+1]%2 && s[i] > s[i+1]) {
            swap(s[i], s[i+1]);
            break;
        }

        else {
            i++;
        }
    }

    return s;    
}