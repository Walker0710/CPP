#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>

using namespace std;

string FirstNonRepeating(string A) {

    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for(int i = 0; i<A.length(); i++) {

        char ch = A[i];

        //increasing count 
        count[ch]++;

        q.push(ch);

        while(!q.empty()) {

            if(count[q.front()] > 1) {

                q.pop();
            }

            else {

                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()) {

            ans.push_back('#');
        }
    }

    return ans;
}

//2nd approch
string FirstElement(string A, int s, int e) {

    string unique = "";
    int ans  

    for(int i = s; i<e; i++) {

        


    }


}


string FirstNonRepeating(string A) {

    for(int i = 0; i<A.length(); i++) {


    }







}
