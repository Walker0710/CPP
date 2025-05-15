#include <bits/stdc++.h>

using namespace std;

// << ,

class ListNode
{

public:
    int val;
    ListNode *next;

    // constructor
    ListNode(int d)
    {
        this->val = d;
        this->next = NULL;
    }
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL)
    return NULL;

    ListNode* ptr = head;
    int cnt = 0;

    while(ptr != NULL && cnt < k) {
        cnt++;
        ptr = ptr -> next;
    }

    if(cnt < k) {
        return head;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* fwd = NULL;
    cnt = 0;

    while(curr != NULL && cnt < k) {
        fwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fwd;
        cnt++;
    }

    head -> next = reverseKGroup(fwd, k);

    return prev;
}