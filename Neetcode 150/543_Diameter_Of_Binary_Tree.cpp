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

pair<int, int> diameterFast(TreeNode* root) {
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root -> left);
    pair<int, int> right = diameterFast(root -> right);

    int leftA = left.first;
    int rightA = right.first;
    int combo = left.second + right.second + 1;

    pair<int, int> ans; 
    ans.first = max(leftA, max(rightA, combo));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(struct TreeNode* root) {

    int ans = diameterFast(root).first;
    return ans;
}