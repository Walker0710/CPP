#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

int maxDepth(TreeNode* root) {

    if (!root)
    return 0;

    int lheight = maxDepth(root->left);
    int rheight = maxDepth(root->right);

    return max(lheight, rheight) + 1;
}