#include<iostream>
#include<vector>

using namespace std;

class BinaryTreeNode {
    public : 
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }   
};

void inOrder(BinaryTreeNode* root, vector<int> &in) {

    if(root == NULL) {

        return ;
    }

    inOrder(root -> left, in);
    in.push_back(root -> data);
    inOrder(root -> right, in);
}

bool twoSumInBST(BinaryTreeNode* root, int target) {

    vector<int> ans;
    inOrder(root, ans);

    int s = 0;
    int e = ans.size() - 1;

    while(s >= e) {

        if(ans[s] + ans[e] == target) {

            return true;
        }

        if(ans[s] + ans[e] > target) {

            e--;
        }

        else {

            s++;
        }
    }
    return false;
} 