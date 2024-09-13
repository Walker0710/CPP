#include <iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>

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

void preorder(TreeNode* root, string &ans) {

    if(root == NULL) {
        return;
    }

    ans.push_back(root -> val);
    preorder(root -> left, ans);    
    preorder(root -> right, ans);
}

void inorder(TreeNode* root, string &ans) {

    if(root == NULL) {

        return;
    }

    inorder(root -> left, ans);
    ans.push_back(root -> val);
    inorder(root -> right, ans);
}

string serialize(TreeNode* root) {

    string pre;
    preorder(root, pre);

    string in;
    inorder(root, in);
    
    string ans = in + pre;
    return ans;
}

int findPos(string in, int element, int n)
{

    for (int i = 0; i < n; i++)
    {

        if (in[i] == element)
        {

            return i;
        }
    }
    return -1;
}

TreeNode *solve(string in, string pre, int &index, int inorderStart, int inorderEnd, int n)
{

    // base case
    if (index == n - 1 || inorderStart > inorderEnd)
    {

        return NULL;
    }

    int element = pre[index++];
    TreeNode *root = new TreeNode(element);
    int positon = findPos(in, element, n);

    root->left = solve(in, pre, index, inorderStart, positon - 1, n);
    root->right = solve(in, pre, index, positon + 1, inorderEnd, n);

    return root;
}

TreeNode* deserialize(string data) {

    string in = "";
    string pre = "";

    for(int i = 0; i<data.length()/2; i++) {

        in.push_back(data[i]);
        pre.push_back(data[i + data.length()/2]);
    }

    int n = data.length()/2;

    int preorderIndex = 0;
    TreeNode *ans = solve(in, pre, preorderIndex, 0, n - 1, n);
    return ans;
}