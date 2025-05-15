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

void reorderList(ListNode* head) {
    if(head == NULL || head -> next == NULL) {
        return ;
    }    

    stack<ListNode*> s;
    ListNode* pt = head;
    int len = 0;

    while(pt != NULL) {
        s.push(pt);
        len++;
        pt = pt -> next;
    }

    ListNode* curr = head;
    ListNode* next1  = curr -> next;

    for(int i = 0; i<len/2; i++) {
        ListNode* top = s.top();
        s.pop();

        curr->next = top;
        curr = top;
        
        curr->next = next1;
        curr = next1;

        if (next1)
        next1 = next1->next;
    }

    if (curr) curr->next = nullptr;

    return ;
}