#include<iostream>
#include<vector>
#include<queue>

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

//1st approch
bool pali(vector<int> ans) {

    int s = 0;
    int e = ans.size() -1;

    while(s<=e) {

        if(ans[s] != ans[e]) {

            return false;
        }

        s++;
        e--;
    }

    return true;
}

bool isSymmetric(TreeNode* root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    vector<int> toCheck;

    while (!q.empty())
    {

        TreeNode *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }

            if(!pali(toCheck)) {

                return false;
            }

            toCheck.clear();
        }

        else
        {
            toCheck.push_back(temp -> data);
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    return true;
}

//3rd approch
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

    bool yo = r1 -> data == r2 -> data;

    if(right && left && yo)
    return true;

    else 
    return false;
}

bool isSymmetric(TreeNode* root) {

    return isMIrrorIMG(root -> left, root -> right);
}