#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {

    if(root == NULL) {

        return NULL;
    }

    if(root -> val == n1 -> val || root -> val == n2 -> val) {

        return root;
    }

    TreeNode* leftAns = lowestCommonAncestor(root -> left, n1, n2);
    TreeNode* rightAns = lowestCommonAncestor(root -> right, n1, n2);

    if(leftAns != NULL && rightAns != NULL) {

        return root;
    }

    else if(leftAns != NULL && rightAns == NULL) {

        return leftAns;
    }

    else if(leftAns == NULL && rightAns != NULL) {

        return rightAns;
    }

    else if(leftAns == NULL && rightAns == NULL) {

        return NULL;
    }

    return NULL;
}