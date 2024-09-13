#include<iostream>

using namespace std;

class BinaryTreeNode 
{
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

//2nd approch
bool isBST(BinaryTreeNode* root, int min, int max) {

    //base case
    if(root == NULL) 
    return true;

    if(root -> data >= min && root -> data <= max) {

        bool left = isBST(root -> left, min, root -> data);
        bool right = isBST(root -> right, root -> data, max);

        return left && right;
    }

    else
    return false;
}

bool validateBST(BinaryTreeNode *root) {

    return isBST(root, INT32_MIN, INT32_MAX);
}