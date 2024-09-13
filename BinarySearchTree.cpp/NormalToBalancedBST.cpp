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

void inOrder(TreeNode* root, vector<int> &in) {

    if(root == NULL) {

        return ;
    }

    inOrder(root -> left, in);
    in.push_back(root -> data);
    inOrder(root -> right, in);
}

TreeNode* solve(vector<int> &yoo, int s, int e) {

    if(s>e)
    return NULL;

    int mid = (e+s)/2;

    TreeNode* yo = new TreeNode(yoo[0]);

    yo -> left = solve(yoo, s, mid - 1);
    yo -> right = solve(yoo , mid + 1, e);

    return yo;
}

TreeNode* balancedBst(TreeNode* root) {

    vector<int> val;
    inOrder(root, val);

    TreeNode* ans = solve(val, 0, val.size() - 1);
    return ans;
}