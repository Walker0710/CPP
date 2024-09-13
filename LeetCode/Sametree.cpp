#include<iostream>
#include<vector>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* r1, TreeNode* r2) {

    if(r1 == NULL && r2 == NULL) {
        return true;
    }
        
    if(r1 == NULL && r2 != NULL) {
        return false;
    }
        
    if(r1 != NULL && r2 == NULL) {
        return false;
    }

    bool left = isSameTree(r1 -> left, r2 -> left);
    bool right = isSameTree(r1 -> right, r2 -> right);

    bool value = r1 -> data == r2 -> data;

    if(left && right && value) {

        return true;
    }

    else {

        return false; 
    }
}