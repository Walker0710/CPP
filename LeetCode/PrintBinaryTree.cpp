#include <iostream>
#include <vector>
#include <math.h>

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

vector<vector<string>> ans;
int hgt(TreeNode *root)
{
    if (!root)
        return 0;

    return 1 + max(hgt(root->left), hgt(root->right));
}
void solve(TreeNode *root, int h, int r, int c)
{
    if (!root)
        return;

    ans[r][c] = to_string(root->val);

    int temp = pow(2, h - r - 2);

    solve(root->left, h, r + 1, c - temp);
    solve(root->right, h, r + 1, c + temp);
}
vector<vector<string>> printTree(TreeNode *root)
{
    ans.clear();
    int h = hgt(root);

    int n = h, m = pow(2, h) - 1;

    ans.resize(n, vector<string>(m, ""));

    solve(root, n, 0, m / 2);

    return ans;
}