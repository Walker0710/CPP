#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root) {

    if (!root)
    return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight, rheight) + 1;

}

int minDepth(TreeNode* root) {

    if (!root)
    return 0;

    if((root -> right == NULL && root -> left != NULL) || (root -> right != NULL && root -> left == NULL))
    return height(root);

    int lheight = minDepth(root->left);
    int rheight = minDepth(root->right);

    return min(lheight, rheight) + 1;
}

//2nd approch
int minDepth(TreeNode* root) {

    if(root && root -> left == NULL && root -> right == NULL)
    return 1;

    int lheight = minDepth(root->left);
    int rheight = minDepth(root->right);

    return min(lheight, rheight) + 1;
}