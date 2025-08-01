#include <iostream>

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

bool isMIrrorIMG(TreeNode* r1, TreeNode* r2) {

    if(r1 == NULL && r2 == NULL) {
        return true;
    }
        
    if(r1 == NULL && r2 != NULL) {
        return false;
    }
        
    if(r1 != NULL && r2 == NULL) {
        return false;
    }

    bool left = isMIrrorIMG(r1 -> left, r2 -> right);
    bool right = isMIrrorIMG(r1 -> right, r2 -> left);

    bool yo = r1 -> val == r2 -> val;

    if(right && left && yo)
    return true;

    else 
    return false;
}

bool isSymmetric(TreeNode* root) {

    return isMIrrorIMG(root -> left, root -> right);
}