#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

void solve(TreeNode *root, TreeNode *p, TreeNode *q, int &ansVal)
{

    if (root == NULL)
        return;

    if (root->val >= p->val && root->val <= q->val)
    {
        ansVal = root->val;
        return;
    }

    if (root->val > p->val && root->val > q->val)
        solve(root->left, p, q, ansVal);

    if (root->val < p->val && root->val < q->val)
        solve(root->right, p, q, ansVal);
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    int ansVal = 0;

    if (q->val > p->val)
        solve(root, p, q, ansVal);

    else
        solve(root, q, p, ansVal);

    TreeNode *ans = new TreeNode(ansVal);

    return ans;
}