#include <bits/stdc++.h>

using namespace std;

// << ,

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// first one O(n^2)
int res = INT_MIN;

int getMax(TreeNode *root)
{
    if (!root)
        return 0;

    int left = getMax(root->left);
    int right = getMax(root->right);
    int path = root->val + std::max(left, right);

    return std::max(0, path);
}

void dfs(TreeNode *root)
{
    if (!root)
        return;

    int left = getMax(root->left);
    int right = getMax(root->right);
    res = std::max(res, root->val + left + right);

    dfs(root->left);
    dfs(root->right);
}

int maxPathSum(TreeNode *root)
{
    dfs(root);
    return res;
}

// O(n)
int dfs(TreeNode *root, int &res)
{
    if (!root)
    {
        return 0;
    }

    int leftMax = max(dfs(root->left, res), 0);
    int rightMax = max(dfs(root->right, res), 0);

    res = max(res, root->val + leftMax + rightMax);
    return root->val + max(leftMax, rightMax);
}

int maxPathSum(TreeNode *root)
{
    int ans = root->val;
    dfs(root, ans);
    return ans;
}