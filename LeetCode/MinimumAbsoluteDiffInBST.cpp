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

int getMinimumDifference(TreeNode *root)
{
    vector<int> sortedNodes;
    inOrderDfs(root, sortedNodes);
    int minDifference = INT32_MAX;

    for (int i = 1; i < sortedNodes.size(); i++)
    {
        minDifference = min(minDifference, sortedNodes[i] - sortedNodes[i - 1]);
    }
    
    return minDifference;
}
void inOrderDfs(TreeNode *root, vector<int> &sortedNodes)
{
    if (root == nullptr)
        return;
    inOrderDfs(root->left, sortedNodes);
    sortedNodes.push_back(root->val);
    inOrderDfs(root->right, sortedNodes);
}