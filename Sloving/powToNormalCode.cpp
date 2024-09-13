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

int titleToNumber2(string s) {

    int ans = 0;
    int power = s.length() - 1;

    for(int i = 0; i<s.length(); i++) {

        int yo = s[i] - 'A' + 1;
        ans = ans + yo*pow(26, power);
        power--;
    }

    return ans;
}

