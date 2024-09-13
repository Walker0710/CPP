#include <iostream>
#include<vector>
#include<queue>
#include<stack>

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

//reccursive way
void solve(TreeNode* root, vector<int> &ans) {

    if(root == NULL)
    return ;

    ans.push_back(root -> val);
    solve(root -> left, ans);
    solve(root -> right, ans);
}

vector<int> preorderTraversal(TreeNode* root) {

    vector<int> ans;
    solve(root, ans);
    return ans;
}

//itrator ways
vector<int> preorderTraversal(TreeNode* root) {

    vector<int> ans;

    if(root == NULL)
    return ;

    stack<TreeNode*> s;
    s.push(root);
    
    while(!s.empty()) {

        TreeNode* temp = s.top();
        s.pop();

        ans.push_back(temp -> val);

        if(temp -> right)
        s.push(temp -> right);

        if(temp -> left)
        s.push(temp -> left);
    }

    return ans;
}
