#include <iostream>
#include <vector>
#include <queue>

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

int countNode(TreeNode* root) {

    if(root == NULL)
    return 0;

    int count = 0;

    int left = countNode(root -> left);
    int right = countNode(root -> right);

    int ans = 1 + left + right;
    return ans;
}

bool isCBT(TreeNode *root, int index, int cnt)
{

    if (root == NULL)
        return true;

    if (index >= cnt)
        return false;

    bool left = isCBT(root->left, 2 * index + 1, cnt);
    bool right = isCBT(root->right, 2 * index + 2, cnt);

    return left && right;
}

bool isCompleteTree(TreeNode *root)
{
    int cnt = countNode(root);
    return isCBT(root, 0, cnt);
}