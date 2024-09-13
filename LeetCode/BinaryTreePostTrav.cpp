#include <iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

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

vector<int> postorderTraversal(TreeNode* root) {

    vector<int> ans;

    if(root == NULL)
    return {};

    stack<TreeNode*> s;
    s.push(root);
    
    while(!s.empty()) {

        TreeNode* temp = s.top();
        s.pop();

        if(temp -> right)
        s.push(temp -> right);

        if(temp -> left)
        s.push(temp -> left);

        ans.push_back(temp -> val);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}