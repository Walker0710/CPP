#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void solve(Node* root, vector<int> &ans, int lvl) {

    //base case
    if(root == NULL) {

        return ;
    }

    //we entered into a new level
    if(lvl == ans.size()) {

        ans.push_back(root -> data);
    }

    solve(root -> right, ans, lvl + 1);
    solve(root -> left, ans, lvl + 1);
}

vector<int> rightView(Node *root) {

    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

//2nd approch
void solve(Node* root, int lvl, map<int, int> &m) {

    if(root == NULL) 
    return ;

    m[lvl] = root -> data;

    solve(root -> left, lvl + 1, m);
    solve(root -> right, lvl + 1, m);
}

vector<int> rightSideView(Node* root) {

    vector<int> ans;
    map<int, int> m;
    solve(root, 0, m);

    for(auto i:m) {

        ans.push_back(i.second);
    }

    return ans;
}