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

int GiveMax(vector<int> &nums, int s, int e) {

    int max = INT32_MIN;
    int index = -1;

    for (int i = s; i <= e; i++)
    {
        if(nums[i] > max) {

            index = i;
            max = nums[i];
        }
    }
    return index;
}

TreeNode* solve(vector<int>& nums, int s, int e) {

    if(s>e) 
    return NULL;

    int index = GiveMax(nums, s, e);
    TreeNode* root = new TreeNode(nums[index]);
    
    TreeNode* leftN = solve(nums, s, index - 1);
    TreeNode* rightN = solve(nums, index + 1, e);

    root -> left = leftN;
    root -> right = rightN;

    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

    TreeNode* ans = solve(nums, 0, nums.size() - 1);
    return ans;
}

