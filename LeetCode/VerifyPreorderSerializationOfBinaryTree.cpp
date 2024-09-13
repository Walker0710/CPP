#include <iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//1st

bool isyoo(string preorder, int i) {

    if((preorder[i] >= '0' && preorder[i] <= '9') && preorder[i+2] == '#' && preorder[i+4] == '#') {

        return true;
    }
    return false;
}

bool isValidSerialization(string preorder) {

    stack<int> s;

    if(preorder.length() == 1 && preorder[0] == '#') 
    return true;

    for(int i = 0; i<preorder.length(); i++) {

        if(preorder[i] == ',') {

            i++;
        }

        if(i == preorder.length() - 5) {

            if(!isyoo(preorder, i)) {

                return false;
            }

            else {

                return true;
            }
        }

        if(preorder[i] <= '9' && preorder[i] >= '0')
        s.push(preorder[i] - '0');

        if(preorder[i] == '#') {

            if(s.empty()) 
            return false;

            else
            s.pop();
        }
    }

    return true;
}

//2nd 

bool isValidSerialization(string preorder) {

    stack<int> s;

    if(preorder.length() == 1 && preorder[0] == '#') 
    return true;

    if(preorder.length() == 3)
    return false;

    for(int i = 0; i<preorder.length() - 1; i++) {

        if(preorder[i] == ',') {

            i++;
        }

        if (i == preorder.length() - 1) {
            
            if (preorder[i] != '#') {
                return false; 
            }
        }

        if(preorder[i] <= '9' && preorder[i] >= '0')
        s.push(preorder[i] - '0');

        if(preorder[i] == '#') {

            if(s.empty()) 
            return false;

            else
            s.pop();
        }
    }

    if(s.empty())
    return true;

    return false;
}

//3rd

bool isValidSerialization(string s) {
    
    int empty = 1;
    int t = 0;
    int n = s.size();

    while (t < n) {

        if (s[t] == ',')
        t++;

        empty += (s[t] == '#') ? -1 : 1;

        while (t < n && s[t] != ',') 
        t++;

        if (empty == 0 && t < n) 
        return false;
    
    }

    return empty==0;
}