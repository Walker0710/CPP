#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

void solveSum(TreeNode* root, int targetSum, int &countToAdd, vector<int> &yo) {

    if(root == NULL) {

        return ;
    }

    yo.push_back(root -> val);

    int sum = 0;

    for(int i = 0; i<yo.size(); i++) {

        sum = sum + yo[i];
    }

    if(sum == targetSum)
    countToAdd++;

    solveSum(root -> left, targetSum, countToAdd, yo);
    solveSum(root -> right, targetSum, countToAdd, yo);

    yo.pop_back();
}

void solve(TreeNode* root, int targetSum, int &count) {

    if(root == NULL)
    return ;

    int countToAdd = 0;
    vector<int> yo;
    solveSum(root, targetSum, countToAdd, yo);

    count = count + countToAdd;

    solve(root -> left, targetSum, count);
    solve(root -> right, targetSum, count);
}

int pathSum(TreeNode* root, int targetSum) {

    int count = 0; 
    solve(root, targetSum, count);

    return count;
}

