#include <iostream>
#include <vector>
#include <queue>

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

// 1st approch
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{

    vector<vector<int>> result;
    vector<int> toPush;
    if (root == NULL)
    {

        return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {

            TreeNode *frontnode = q.front();
            q.pop();

            // choosing between normal or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontnode->val;

            if (frontnode->left)
            {

                q.push(frontnode->left);
            }

            if (frontnode->right)
            {

                q.push(frontnode->right);
            }
        }

        // direction change
        leftToRight = !leftToRight;

        for (auto i : ans)
        {

            toPush.push_back(i);
        }

        result.push_back(toPush);
        toPush.clear();
    }

    return result;
}

//2nd approch
int height(TreeNode *root)
{
    if (!root)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}
void currentlevel(TreeNode *root, int level, bool order, vector<int> &ans)
{
    if (!root)
        return;
    if (level == 1)
    {
        ans.push_back(root->val);
        return;
    }
    if (order)
    {
        currentlevel(root->left, level - 1, order, ans);
        currentlevel(root->right, level - 1, order, ans);
    }
    else
    {
        currentlevel(root->right, level - 1, order, ans);
        currentlevel(root->left, level - 1, order, ans);
    }
}
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    int h = height(root);
    vector<vector<int>> res;
    bool order = true;
    for (int i = 1; i < h + 1; i++)
    {
        vector<int> ans;
        currentlevel(root, i, order, ans);
        res.push_back(ans);
        order = !order;
    }
    return res;
}