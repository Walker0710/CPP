#include <iostream>
#include <cmath>

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

int getLeftDepth(TreeNode *node)
{
    int depth = 0;
    while (node)
    {
        depth++;
        node = node->left;
    }
    return depth;
}

int getRightDepth(TreeNode *node)
{
    int depth = 0;
    while (node)
    {
        depth++;
        node = node->right;
    }
    return depth;
}

int countNodes(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int leftDepth = getLeftDepth(root);
    int rightDepth = getRightDepth(root);

    if (leftDepth == rightDepth)
    {
        // If the left and right subtrees have the same depth, the tree is a full binary tree
        return pow(2, leftDepth) - 1;
    }
    else
    {
        // If the left and right subtrees have different depths, recursively count nodes
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

