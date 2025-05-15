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

void insertAtTail(ListNode* &head, ListNode* &tail, int n) {
    ListNode* temp = new ListNode(n);

    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    else {
        tail -> next = temp;
        tail = temp;
    }
}

ListNode* solve(ListNode* l1, ListNode* l2) {
    int digit = 0;
    int carry = 0;
    int sum = 0;

    ListNode* ansHead = NULL;
    ListNode* ansTail = NULL;

    while(l1 != NULL && l2 != NULL) {
        sum = l1 -> val + l2 -> val + carry; 

        carry = sum/10;
        digit = sum%10;

        insertAtTail(ansHead, ansTail, digit);

        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    while (l1 != NULL) 
    {
        sum = l1 -> val + carry;
        carry = sum/10;
        digit = sum%10;

        insertAtTail(ansHead, ansTail, digit);

        l1 = l1 -> next;
    }

    while (l2 != NULL) 
    {
        sum = l2 -> val + carry;
        carry = sum/10;
        digit = sum%10;

        insertAtTail(ansHead, ansTail, digit);

        l2 = l2 -> next;
    }

    while(carry != 0) {

        sum = carry;
        digit = sum%10;
        carry = sum/10;

        insertAtTail(ansHead, ansTail, digit);
    }

    return ansHead;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = solve(l1, l2);         
    
    return ans;
}