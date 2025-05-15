#include <bits/stdc++.h>

using namespace std;

// << ,

struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q != NULL) 
    return false;

    if(p != NULL && q == NULL) 
    return false;

    if(p == NULL && q == NULL)
    return true;
    
    if(p -> val != q -> val) 
    return false;
    
    bool leftt = isSameTree(p -> left, q -> left);
    bool rightt = isSameTree(p -> right, q -> right);

    return leftt && rightt;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL) 
    return false;

    if (isSameTree(root, subRoot)) 
    return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
