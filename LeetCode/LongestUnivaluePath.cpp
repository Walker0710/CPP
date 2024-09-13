#include <iostream>
#include <vector>

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

void solve(TreeNode* root, int &count, int &max) {

    if(root == NULL || (root -> left == NULL && root -> right == NULL))  
    return;

    if(root -> val == root -> left -> val) {

        count++;
        solve(root -> left, count, max);
    }

    if(root -> val == root -> right -> val) {

        count++;
        solve(root -> right, count, max);
    } 

    //if(root -> left && root -> right && root -> val != root -> right -> val && root -> val != root -> left -> val) {

        if(count > max) {
            
            max = count;
            count = 0;
        }

    //}

    solve(root -> left, count, max);
    solve(root -> right, count, max);
}

int longestUnivaluePath(TreeNode* root) {

    if(root == NULL)
    return 0;

    int count = 0;
    int max = 0;
    solve(root, count, max);

    return max;
}

void solve(TreeNode* root, int &count, int &max) {

    if(root == NULL || (root -> left == NULL && root -> right == NULL))  
    return;

    if(root -> val == root -> left -> val) {

        count++;
        solve(root -> left, count, max);
    }

    if(root -> val == root -> right -> val) {

        count++;
        solve(root -> right, count, max);
    } 

    if(count > max) {
            
        max = count;
        count = 0;
    }

    solve(root -> left, count, max);
    solve(root -> right, count, max);
}

int longestUnivaluePath(TreeNode* root) {

    if(root == NULL)
    return 0;

    int count = 0;
    int max = 0;
    solve(root, count, max);

    return max;
}






















void solve(TreeNode* root, int &count, int &max) {
    if (root == NULL)  
        return;

    int leftCount = 0, rightCount = 0;
    
    if (root->left && root->val == root->left->val) {
        solve(root->left, leftCount, max);
        count = 1 + leftCount;
    }

    if (root->right && root->val == root->right->val) {
        solve(root->right, rightCount, max);
        count = max(count, 1 + rightCount);
    }

    // Update max and reset count
    if (root->left && root->right && root->val == root->left->val && root->val == root->right->val) {
        max = max(max, 2 + leftCount + rightCount);
        count = max(leftCount, rightCount) + 1;
    }

    // Recursive calls
    solve(root->left, leftCount, max);
    solve(root->right, rightCount, max);
}

int longestUnivaluePath(TreeNode* root) {
    if (root == NULL)
        return 0;

    int count = 0;
    int max = 0;
    solve(root, count, max);

    return max;
}
