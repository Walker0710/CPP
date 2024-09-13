#include<iostream>
#include<vector>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inOrder(TreeNode* root, vector<int> &in) {

    if(root == NULL) {

        return ;
    }

    inOrder(root -> left, in);
    in.push_back(root -> data);
    inOrder(root -> right, in);
}

TreeNode* flatten(TreeNode* root) {

    vector<int> inOrderVal;
    inOrder(root, inOrderVal);
    int n = inOrderVal.size();

    TreeNode* newRoot = new TreeNode(inOrderVal[0]);

    TreeNode* curr = newRoot;

    for(int i = 1; i<n; i++) {

        TreeNode* temp = new TreeNode(inOrderVal[i]);
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }

    curr -> left = NULL;
    curr -> right = NULL;

    return newRoot;
}