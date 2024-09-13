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

TreeNode *solve(TreeNode *&root, int low, int high)
{

    if (root == NULL)
        return NULL;

    if (root->val < low)
    {

        // 0 child or only left child
        if ((root->right == NULL && root->left == NULL) || (root->right == NULL && root->left != NULL))
        {

            delete (root);
            return NULL;
        }

        // right child only or 2 children
        else if ((root->right != NULL && root->left == NULL) || (root->right != NULL && root->left != NULL))
        {

            if (root->right->val >= low)
            {

                TreeNode *temp = root->right;
                delete (root);
                return temp;
            }

            if (root->right->val < low)
            {

                delete (root);
                return NULL;
            }
        }
    }

    else if (root->val > high)
    {

        // 0 child or 1 right child
        if ((root->right == NULL && root->left == NULL) || (root->left == NULL && root->right != NULL))
        {

            delete (root);
            return NULL;
        }

        // left child only or 2 children
        else if ((root->right == NULL && root->left != NULL) || (root->right != NULL && root->left != NULL))
        {

            if (root->left->val <= high)
            {

                TreeNode *temp = root->left;
                delete (root);
                return temp;
            }

            if (root->left->val > high)
            {

                delete (root);
                return NULL;
            }
        }
    }

    else
    {

        TreeNode *leftN = solve(root->left, low, high);
        TreeNode *rightN = solve(root->right, low, high);

        root->left = leftN;
        root->right = rightN;
    }
    return root;
}

TreeNode *trimBST(TreeNode *root, int low, int high)
{

    TreeNode *ans = solve(root, low, high);
    return ans;
}

// 2nd approch
TreeNode *solve(TreeNode *&root, int low, int high)
{

    if (root == NULL)
        return NULL;

    if (root->val < low)
    {

        return solve(root->right, low, high);
    }

    else if (root->val > high)
    {

        return solve(root->left, low, high);
    }

    else
    {

        TreeNode *leftN = solve(root->left, low, high);
        TreeNode *rightN = solve(root->right, low, high);

        root->left = leftN;
        root->right = rightN;
    }

    return root;
}

TreeNode *trimBST(TreeNode *root, int low, int high)
{

    TreeNode *ans = solve(root, low, high);
    return ans;
}