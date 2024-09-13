#include <iostream>
#include <vector>
#include <queue>
#include<stack>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> &order)
{

    if (root == NULL)
        return;

    inorder(root->left, order);
    order.push_back(root->val);
    inorder(root->right, order);
}

int sum(vector<int> order, int n)
{

    int sum = 0;

    for (int i = 0; i < order.size(); i++)
    {

        if (order[i] >= n)
        {

            sum = sum + order[i];
        }
    }

    return sum;
}

void solve(TreeNode *root, vector<int> order)
{

    if (root == NULL)
        return;

    root->val = sum(order, root->val);

    solve(root->left, order);
    solve(root->right, order);
}

TreeNode *convertBST(TreeNode *root)
{
    vector<int> order;
    inorder(root, order);
    solve(root, order);
    return root;
}

//2nd approch
void dfsIn(TreeNode *root, stack<TreeNode *> &st)
{
    if (root == NULL)
    return;
    
    dfsIn(root->left, st);
    st.push(root);
    dfsIn(root->right, st);
}

TreeNode *convertBST(TreeNode *root)
{
    stack<TreeNode *> st;
    dfsIn(root, st);
    int sum = 0;
    while (!st.empty())
    {
        TreeNode *p = st.top();
        st.pop();
        sum += p->val;
        p->val = sum;
    }
    return root;
}