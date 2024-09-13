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

BinaryTreeNode* solve(vector<int> &preorder, int mini, int maxi, int &i) {

    if(i >= preorder.size()) {

        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi) {

        return NULL;
    }

    BinaryTreeNode* root = new BinaryTreeNode(preorder[i++]);
    root -> left = solve(preorder, mini, root -> data, i);
    root -> right = solve(preorder, root -> data, maxi, i);
    return root;
}

BinaryTreeNode* preorderToBST(vector<int> &preorder) {

    int mini = INT32_MIN;
    int maxi = INT32_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}

