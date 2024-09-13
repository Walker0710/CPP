#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

//1st approch
string reverseWords(string s) {

    int p1 = s.length() - 1;
    int p2 = 0;
    int p3 = s.length() - 1;

    string ans;
    string yo;

    while(p1 >= 0) {

        while(s[p1] == ' ' && p1 >= 0) {

            p1--;
        }

        while(s[p1] != ' ' && p1 >= 0 ) {

            p1--;
        }

        if(p1 == -1) {

            p1 == 0;
            ans.push_back(' ');
        }

        p2 = p1;

        while(p1 <= p3) {

            ans.push_back(s[p1]);
            p1++;
        }

        while (s[p2] == ' ' && p2 >= 0) {

            p2--;
        }

        p3 = p2;
        p1 = p2;
    }

    for(int i = 1; i<ans.length(); i++ ) {

        char c = ans[i];
        yo.push_back(c);
    }

    return yo;
}

int main() {

    string s = "the sky is blue";

    string ans = reverseWords(s);

    for(int i = 0; i<ans.length(); i++) {

        cout<<ans[i];
    }
}

//2nd approch ye wla approch kisi se puch lena ek bar 
string reverseWords(string s) {
        
    reverse(s.begin(), s.end());
    istringstream iss (s);
    string res;
    string tmp;
        
    while(iss>>tmp){
        
        reverse(tmp.begin(), tmp.end());
        res+=(' '+tmp);
    }
        
    if (res.size()>0){
            
        res = res.substr(1);
    }
    
    return res;
}