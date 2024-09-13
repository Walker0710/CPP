#include <iostream>
#include<vector>

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

void solve(TreeNode* root, int &sum, string arr) {

    if(root == NULL)
    return ;

    arr.push_back(root -> val + '0');

    if(root -> left == NULL && root -> right == NULL) {

        int sumToPush = stoi(arr);
        sum = sum + sumToPush;
    }

    solve(root -> left, sum, arr);
    solve(root -> right, sum, arr);

    arr.pop_back();
}

int sumNumbers(TreeNode* root) {

    int sum = 0;
    string arr;

    solve(root, sum, arr);

    return sum;
}