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

vector<vector<int>> levelOrder(TreeNode* root) {

    if(root == NULL)
    return {};

    vector<vector<int>> ans;
    vector<int> toPush;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode* top = q.front();
        q.pop();

        if(top == NULL) {
            ans.push_back(toPush);
            toPush.clear();

            if(!q.empty())
            q.push(NULL);
        }

        else {
            toPush.push_back(top -> val);

            if(top -> left) 
            q.push(top -> left);

            if(top -> right) 
            q.push(top -> right);
        }
    }

    return ans;
}