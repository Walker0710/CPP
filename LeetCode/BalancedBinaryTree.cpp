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

pair<bool, int> solve(TreeNode* root) {

    if(root == NULL) {

        pair<bool, int> p = {true, 0};
        return p;
    }

    pair<bool, int> left = solve(root -> left);
    pair<bool, int> right = solve(root -> right);

    bool leftB = left.first;
    bool rightB = right.first;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    bool yoo = abs(left.second - right.second) <= 1;

    if(leftB && rightB && yoo) {

        ans.first = true;
    }

    else {

        ans.first = false;
    }

    return ans;
}

bool isBalanced(TreeNode* root) {

    pair<bool, int> ans = solve(root);

    return ans.first;
}