#include<iostream>
#include<vector>
#include<algorithm>
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

//1st approch
vector<vector<int>> levelOrderBottom(TreeNode* root) {

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

    reverse(ans.begin(), ans.end());
    return ans;
}

//2nd approch
int height(TreeNode* node) {

    //base case 
    if(node == NULL) {

        return 0;
    }

    int left = height(node -> left);
    int right = height(node -> right);
    int ans = max(left, right);

    return ans + 1;
}

void currentLvl(TreeNode* root, int lvl, vector<int> &arr) {

    if(root == NULL) 
    return ;

    if(lvl == 1) {

        arr.push_back(root -> val);
        return ;
    }

    currentLvl(root -> left, lvl - 1, arr);
    currentLvl(root -> right, lvl - 1, arr);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {

    int Total = height(root);
    vector<vector<int>> ans;

    for(int i = Total; i >= 1; i--) {

        vector<int> toInsert;
        currentLvl(root, i, toInsert);
        ans.push_back(toInsert);
    }

    return ans;
}
