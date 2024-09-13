#include <iostream>
#include<vector>

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

int height(TreeNode *root)
{
    if (!root)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
} 

void currentlevel(TreeNode *root, int level, int &max)
{
    if (!root)
        return;

    if (level == 1)
    {
        if(max < root -> val)
        max = root -> val;

        return;
    }

    currentlevel(root->left, level - 1, max);
    currentlevel(root->right, level - 1, max);    
}

vector<int> largestValues(TreeNode* root) {

    vector<int> ans;
    int h = height(root);
    
    for(int i = 1; i<=h; i++) {

        int max = INT32_MIN;
        currentlevel(root, i, max);
        ans.push_back(max);
    }

    return ans;
}