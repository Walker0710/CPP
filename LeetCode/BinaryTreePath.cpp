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

void solve(TreeNode *root, string toPush, vector<string> &ans)
{

    if (root == NULL)
    {

        return;
    }

    toPush.append(to_string(root->val));

    if (root->left == NULL && root->right == NULL)
    {

        ans.push_back(toPush);
        return;
    }

    toPush = toPush + "->";

    solve(root->left, toPush, ans);
    solve(root->right, toPush, ans);
}

vector<string> binaryTreePaths(TreeNode *root)
{

    vector<string> ans;
    string toPush;

    solve(root, toPush, ans);

    return ans;
}

// 2nd approch
void Preorder(TreeNode *root, string temp, vector<string> &ans)
{
    if (root)
    {
        temp.append(to_string(root->val));
        if (!root->left && !root->right)
            ans.push_back(temp);
        else
        {
            temp.append("->");
            Preorder(root->left, temp, ans);
            Preorder(root->right, temp, ans);
        }
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    string temp = "";
    Preorder(root, temp, ans);
    return ans;
}