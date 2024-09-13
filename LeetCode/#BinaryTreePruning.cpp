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

/*
bool solve(TreeNode* &root) {

    if(root == NULL)
    return true;

    if(root -> left == NULL && root -> right == NULL) {

        if(root -> val == 0) 
        return false;

        else 
        return true;
    }

    bool leftN = solve(root -> left);
    bool rightN = solve(root -> right);

    if(!leftN)
    root -> left = NULL;

    if(!rightN)
    root -> right = NULL;

    if(root -> val == 1)
    return true;

    else 
    return false;

    return true;
}

TreeNode* pruneTree(TreeNode* root) {

    bool ans = solve(root);
    return root;
}
*/

TreeNode* solve(TreeNode* root) {

    if(root == NULL)
    return NULL;

    if(root -> left && root -> right) {

        if(root -> val == 0) {

            delete(root);
            return NULL;
        }
    }

    root -> left = solve(root -> left);
    root -> right = solve(root -> right);

    return root;
}

TreeNode* pruneTree(TreeNode* root) {

    TreeNode* ans = solve(root);
    return ans;
}
