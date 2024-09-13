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

void solve(TreeNode* root, int value) {

    if(root == NULL)
    return;

    if(root -> right == NULL && root -> left == NULL) {

        if(root -> val > value) {

            TreeNode* yo = new TreeNode(value);
            root -> left = yo;
        }

        else {

            TreeNode* yo = new TreeNode(value);
            root -> right = yo;
        }

        return;
    }

    if(root -> val > value) {

        if(root -> left == NULL) {

            TreeNode* yo = new TreeNode(value);
            root -> left = yo;
            return;
        }

        else 
        solve(root -> left, value);
    }

    else {

        if(root -> right == NULL) {

            TreeNode* yo = new TreeNode(value);
            root -> right = yo;
            return;
        }

        else 
        solve(root -> right, value);
    }
}

TreeNode* insertIntoBST(TreeNode* root, int val) {

    if(root == NULL) {

        TreeNode* yo = new TreeNode(val);
        return yo;
    }

    solve(root, val);
    return root;
}