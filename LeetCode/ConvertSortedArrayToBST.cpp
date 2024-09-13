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

TreeNode* solve(vector<int>& nums, int first, int last) {

    int mid = (first + last)/2;

    if(first > last)
    return ;

    TreeNode* root = new TreeNode(nums[mid]);

    root -> left = solve(nums, first, mid - 1);
    root -> right = solve(nums, mid + 1, last);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {

    TreeNode* ans = solve(nums, 0, nums.size() - 1);
    return ans;
}
