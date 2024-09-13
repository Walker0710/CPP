#include<iostream>
#include<vector>
#include<map>
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

void createMapping(vector<int> in, map<int, int> nodeToIndex, int n)
{

    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

TreeNode *solve(vector<int> in, vector<int> post, int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{
    // base case
    if (index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = post[index--];
    TreeNode *root = new TreeNode(element);
    int positon = nodeToIndex[element];
    root->right = solve(in, post, index, positon + 1, inorderEnd, n, nodeToIndex);
    root->left = solve(in, post, index, inorderStart, positon - 1, n, nodeToIndex);

    return root;
}

TreeNode* buildTree(vector<int>& in, vector<int>& post) {

    int n = in.size();
    int postorderIndex = n-1;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    TreeNode *ans = solve(in, post, postorderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}