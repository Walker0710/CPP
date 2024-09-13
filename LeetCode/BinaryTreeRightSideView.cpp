#include <iostream>
#include<vector>
#include<queue>
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

void solve(TreeNode* root, int lvl, map<int, int> &m) {

    if(root == NULL) 
    return ;

    m[lvl] = root -> val;

    solve(root -> left, lvl + 1, m);
    solve(root -> right, lvl + 1, m);
}

vector<int> rightSideView(TreeNode* root) {

    vector<int> ans;
    map<int, int> m;
    solve(root, 0, m);

    for(auto i:m) {

        ans.push_back(i.second);
    }

    return ans;
}


