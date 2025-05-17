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

void createMapping(vector<int> in, unordered_map<int, int> &nodeToIndex, int n)
{

    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

TreeNode *solve(vector<int> in, vector<int> pre, int &index, int inorderStart, int inorderEnd, int n, unordered_map<int, int> &nodeToIndex)
{
    // base case
    if (index == n || inorderStart > inorderEnd)
    {

        return NULL;
    }

    int element = pre[index++];
    TreeNode *root = new TreeNode(element);
    int positon = nodeToIndex[element];
    root->left = solve(in, pre, index, inorderStart, positon - 1, n, nodeToIndex);
    root->right = solve(in, pre, index, positon + 1, inorderEnd, n, nodeToIndex);

    return root;
}

TreeNode *buildTree(vector<int> &pre, vector<int> &in)
{
    int preorderIndex = 0;
    int n = in.size();
    unordered_map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    TreeNode *ans = solve(in, pre, preorderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}


// approch 2
TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preS, int preE,
                int inS, int inE, unordered_map<int, int> &mpp)
{
    if (preS > preE || inS > inE)
        return NULL;

    TreeNode *root = new TreeNode(preorder[preS]);

    int inRoot = mpp[root->val];
    int left = inRoot - inS;

    root->left = build(preorder, inorder, preS + 1, preS + left, inS, inRoot - 1, mpp);
    root->right = build(preorder, inorder, preS + left + 1, preE, inRoot + 1, inE, mpp);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }

    return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, mpp);
}