#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <stack>

using namespace std;

string reverseWords(string S) {

    string ans = "";
    string temp = "";

    for(int i = S.length() - 1; i>=0; i--) {

        if(S[i] == '.') {

            reverse(temp.begin(), temp.end());
            ans = ans + temp;
            ans.push_back('.');
            temp = "";
        }

        else {
            temp.push_back(S[i]);
        }
    }

    reverse(temp.begin(), temp.end());
    ans = ans + temp;
    return ans;
}