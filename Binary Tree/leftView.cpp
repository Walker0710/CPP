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

    solve(root -> left, ans, lvl + 1);
    solve(root -> right, ans, lvl + 1);
}

vector<int> leftView(Node *root) {

    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}