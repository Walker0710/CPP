#include<iostream>

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

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q) {

    if(root == NULL) {

        return NULL;
    }

    if(root -> data < P -> data && root -> data < Q -> data) {

        return LCAinaBST(root -> right, P, Q);
    }

    if(root -> data > P -> data && root -> data > Q -> data) {

        return LCAinaBST(root -> left, P, Q);
    }

    return root;
}

//2nd 
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q) {

    while (root != NULL)
    {
        if(root -> data < P -> data && root -> data < Q -> data) {

            root = root -> right;
        }

        if(root -> data > P -> data && root -> data > Q -> data) {

            root = root -> left;
        }

        else{

            return root;
        }
    }
}
