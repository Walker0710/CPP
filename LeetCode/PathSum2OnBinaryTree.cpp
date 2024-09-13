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

//1st approch
void solve(TreeNode* root, int targetSum, vector<int> &toPush, vector<vector<int>> &ans) {

    if(root == NULL)
    return ;

    toPush.push_back(root -> val);

    int sum = 0;

    for(int i =0; i<toPush.size(); i++) {

        sum = sum + toPush[i];
    }

    if(root -> right == NULL && root -> left == NULL && sum == targetSum) 
    ans.push_back(toPush); 

    solve(root -> left, targetSum, toPush, ans);
    solve(root -> right, targetSum, toPush, ans);

    toPush.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    vector<vector<int>> ans; 
    vector<int> toPush;
    solve(root, targetSum, toPush, ans);
    return ans;
}

//2nd approch
void solve(TreeNode* root, int targetSum, vector<int> &toPush, vector<vector<int>> &ans) {

    if(root == NULL)
    return ;

    toPush.push_back(root -> val);

    if(root -> right == NULL && root -> left == NULL && root -> val == targetSum) 
    ans.push_back(toPush);

    solve(root -> left, targetSum - root -> val, toPush, ans);
    solve(root -> right, targetSum - root -> val, toPush, ans);

    toPush.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    vector<vector<int>> ans;
    vector<int> toPush;
    solve(root, targetSum, toPush, ans);
    return ans;
}

