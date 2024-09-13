#include<iostream>
#include<vector>

using namespace std;

//1st approch
int lengthOfLastWord(string s) {

    int length = 0;
    vector<int> ans;
    int count = 0;

    for(int i = 0; i<s.length(); i++) {

        if(s[i] != ' ') {

            count++;
        }
    }

    for(int i = 0; i<s.length(); i++) {

        if(s[i] != ' ') {

            length++;
            count--;
        }

        if(count == 0) {

            ans.push_back(length);
        }

        if(s[i] == ' ' && count != 0) {

            ans.push_back(length);
            length = 0;
        }
    }

    return ans[ans.size() - 1];
}

//2nd approch
int lengthOfLastWord(string s) {

    int i = s.length() - 1;
    int length = 0;

    while(i >= 0 && s[i] == ' ') {

        i--;
    }

    while(i >= 0 && s[i] != ' ') {

        length++;
        i--;
    }

    return length;
}

