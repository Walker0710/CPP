#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve(TreeNode* root, int targetSum, int &count, vector<int> &arr) {

    if(root == NULL) {

        return ;
    }

    arr.push_back(root -> val);

    solve(root -> left, targetSum, count, arr);
    solve(root -> right, targetSum, count, arr);

    int sum = 0;

    for(int i = 0; i<arr.size(); i++) {

        sum = sum + arr[i];
    }

    if(sum == targetSum)
    count++;

    arr.pop_back();
}

bool hasPathSum(TreeNode* root, int targetSum) {

    vector<int> arr;
    int count = 0;

    solve(root, targetSum, count, arr);

    if(count == 0)
    return false;

    else 
    return true;
}

//2nd approch
bool hasPathSum(TreeNode* root, int targetSum) {

    if (!root) {
    return false;
    }
        
    if (!root->left && !root->right) {
        return targetSum == root->val;
    }
        
    bool left_sum = hasPathSum(root->left, targetSum - root->val);
    bool right_sum = hasPathSum(root->right, targetSum - root->val);
        
    return left_sum || right_sum;
}