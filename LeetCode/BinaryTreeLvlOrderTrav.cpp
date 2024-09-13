#include<iostream>
#include<vector>
#include<queue>

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

vector<vector<int>> levelOrder(TreeNode* root) {

    if(root == NULL)
    return {};

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    vector<vector<int>> ans;
    vector<int> toPush;

    while(!q.empty()) {

        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL) {

            ans.push_back(toPush);

            if(!q.empty()) 
            q.push(NULL);

            toPush.clear();
        }

        else {

            toPush.push_back(temp -> val);
            if(temp -> left)
            q.push(temp -> left);

            if(temp -> right) 
            q.push(temp -> right);
        }
    }

    return ans;
}