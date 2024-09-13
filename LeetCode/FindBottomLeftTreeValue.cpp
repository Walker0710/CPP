#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root)
{
    if (!root)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}

void currentlevel(TreeNode *root, int level, vector<int> &ans)
{
    if (!root)
    return;

    if (level == 1)
    {
        ans.push_back(root->val);
        return;
    }

    currentlevel(root->left, level - 1, ans);
    currentlevel(root->right, level - 1, ans);
}

int findBottomLeftValue(TreeNode *root)
{
    vector<int> ans;
    int h = height(root);

    currentlevel(root, h, ans);

    int yo = ans.front();
    return yo;
}