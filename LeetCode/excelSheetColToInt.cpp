#include<iostream>
#include<math.h>

using namespace std;

int titleToNumber(string s) {

    int ans = 0;

    for(int i = 0; i<s.length(); i++) {

        ans = ans * 26 + (s[i] - 'A' + 1);
    }

    return ans;
}