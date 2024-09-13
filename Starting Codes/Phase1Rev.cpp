#include<iostream>
#include<vector>

using namespace std;

bool valid(char ch) {

    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {

        return 1;
    }

    else{

        return 0;
    }
}

char ToLower(char ch) {

    if( ch >= 'a' && ch <= 'z') {

        return ch;
    }

    else {

        char temp = ch - 'A' + 'a';
    }
}

bool checkPall(string a) {

    int s = 0;
    int e = a.size()-1;

    while(s<=e) {

        if(a[s] != a[e]) {

            return 0;
        }

        else{

            e--;
            s++;
        }
    }

    return 1;
}

