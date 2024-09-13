#include <iostream>

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

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{

    if (root == NULL)
    {

        return;
    }

    TreeNode *temp = root;
    int succ = -1;
    int pred = -1;

    while (temp->data != key)
    {

        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }

        if (temp->data < key)
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    TreeNode *lefttree = temp->left;

    while (lefttree != NULL)
    {
        pred = lefttree->data;
        lefttree = lefttree->right;
    }

    TreeNode *righttree = temp->right;

    while (righttree != NULL)
    {

        succ = righttree->data;
        righttree = righttree->left;
    }

    pair<int, int> ans = make_pair(pred, succ);

    return ans;
}