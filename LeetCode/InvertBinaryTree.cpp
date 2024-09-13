#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {

    if(root == NULL)
    return NULL;

    TreeNode* left = invertTree(root -> left);
    TreeNode* right = invertTree(root -> right);

    TreeNode* ans = new TreeNode(root -> val);

    ans -> left = right;
    ans -> right = left;

    return ans;
}