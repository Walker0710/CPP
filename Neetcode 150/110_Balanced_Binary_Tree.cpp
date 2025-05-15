#include <bits/stdc++.h>

using namespace std;

// << ,

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

    pair<bool, int> leftt = solve(root -> left);
    pair<bool, int> rightt = solve(root -> right);

    int yoo = abs(leftt.second - rightt.second);

    if(yoo <= 1)
    yoo = true;

    else 
    yoo = false;

    pair<bool, int> ans;

    if(leftt.first && rightt.first && yoo) {
        ans.first = true;
    }

    else {
        ans.first = false;
    }

    ans.second = max(leftt.second, rightt.second) + 1;

    return ans;
}

bool isBalanced(TreeNode* root) {
    pair<bool, int> ans = solve(root);
    
    return ans.first;
}