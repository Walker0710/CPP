#include <bits/stdc++.h>

using namespace std;

// << ,

bool isValid(string s) {
    stack<char> st;

    for(int i = 0; i<s.length(); i++) {
        char c = s[i];
        
        if(c == '{' || c == '[' || c == '(') {
            st.push(c);
        }

        else {
            if(c == '}' || c == ']' || c == ')') {
                
            }


        }
    }
}