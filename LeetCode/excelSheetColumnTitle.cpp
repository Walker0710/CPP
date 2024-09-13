#include<iostream>
#include<algorithm>

using namespace std;

string convertToTitle(int n) {

    string ans;

    while(n > 0) {

        int digit = n%26;

        if(digit == 0) {

            ans.push_back('Z');
            n--;
        }

        else {

            ans.push_back(digit + 'A' - 1);
        }

        n = n/26;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}