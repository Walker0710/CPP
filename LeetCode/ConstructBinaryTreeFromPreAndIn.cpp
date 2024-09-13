#include<iostream>
#include<vector>
#include<unordered_map>
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

int findPos(vector<int> in, int element, int n)
{

    for (int i = 0; i < n; i++)
    {

        if (in[i] == element)
        {

            return i;
        }
    }
    return -1;
}

TreeNode *solve(vector<int> in, vector<int> pre, int &index, int inorderStart, int inorderEnd, int n)
{

    // base case
    if (index == n - 1 || inorderStart > inorderEnd)
    {

        return NULL;
    }

    int element = pre[index++];
    TreeNode *root = new TreeNode(element);
    int positon = findPos(in, element, n);

    root->left = solve(in, pre, index, inorderStart, positon - 1, n);
    root->right = solve(in, pre, index, positon + 1, inorderEnd, n);

    return root;
}

TreeNode* buildTree(vector<int>& pre, vector<int>& in) {

    int preorderIndex = 0;
    int n = pre.size();

    TreeNode *ans = solve(in, pre, preorderIndex, 0, n - 1, n);
    return ans;
}

//2nd approch
void createMapping(vector<int> in, unordered_map<int, int> nodeToIndex, int n)
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

TreeNode* buildTree(vector<int>& pre, vector<int>& in) {

    int preorderIndex = 0;
    int n = in.size();
    unordered_map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    TreeNode *ans = solve(in, pre, preorderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}


