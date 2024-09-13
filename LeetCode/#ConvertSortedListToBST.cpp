#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
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
*/

ListNode getMid(ListNode* head) {

    ListNode* fast = head -> next;
    ListNode* slow = head;

    while (fast != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;

        if(fast != NULL)
        fast = fast -> next;
    }

    return slow;
}

TreeNode* solve(ListNode* head, ListNode* start, ListNode* last) {

    ListNode* mid = getMid




}

TreeNode* sortedListToBST(ListNode* head) {

    ListNode* start = head;
    ListNode* last = head;

    while(last -> next != NULL) {

        last = last -> next;
    }

    TreeNode* ans = solve(head, start, last); 
    return ans;
}