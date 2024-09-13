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

void AddingNodes(TreeNode *root, int val, int depth)
{
    if (!root)
    return;

    

    if (depth == 1)
    {
        TreeNode *leftRoot = root->left;
        TreeNode *toAdd1 = new TreeNode(val);
        root->left = toAdd1;
        toAdd1->left = leftRoot;

        TreeNode *rightRoot = root->right;
        TreeNode *toAdd2 = new TreeNode(val);
        root->right = toAdd2;
        toAdd2->right = rightRoot;

        return;
    }

    AddingNodes(root->left, val, depth - 1);
    AddingNodes(root->right, val, depth - 1);
}

TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if(depth == 1) {

        TreeNode* ans = new TreeNode(val);
        ans -> left = root;
        return ans;
    }

    AddingNodes(root, val, depth - 1);

    return root;
}