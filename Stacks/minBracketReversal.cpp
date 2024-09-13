#include<iostream>
#include<stack>

using namespace std;

int findMinimumCost(string str) {

    if(str.length()%2 == 1) {

        return -1;
    }

    stack<char> s;
    for(int i = 0; i<str.length(); i++) {

        char ch = str[i];

        if(ch == '{') {

            s.push(ch);
        }

        else {

            //ch is closed bracket
            if(!s.empty() && s.top() == '{') {

                s.pop();
            }

            else {

                s.push(ch);
            }
        }
    }

    int open = 0;
    int close = 0;

    while(!s.empty()) {

        if(s.top() == '{') {

            open++;
        }

        else {

            close++;
        }

        s.pop();
    }

    if(close == 0) {

        return (open+1)/2;
    }

    if(open == 0) {

        return (close+1)/2;
    }

    if(open != 0 && close != 0) {

        return ((open+1)/2 + (close+1)/2);
    }
}