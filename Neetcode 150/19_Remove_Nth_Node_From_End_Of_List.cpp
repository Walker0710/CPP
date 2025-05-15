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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode* ptr = head;
    
    while(ptr != NULL) {
        size++;
        ptr = ptr -> next;
    } 

    if(n == size) {
        return head -> next;
    }

    if(n == 1) {
        int cnt = size - 2;
        ListNode* curr = head;

        while (cnt)
        {
            curr = curr -> next;
            cnt--;
        }

        curr -> next = NULL;

        return head;
    }

    else {
        ListNode* prev = NULL;
        ListNode* curr = head;

        int cnt = size - n;

        while (cnt)
        {
            prev = curr;
            curr = curr -> next;
            cnt--;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;

        return head;
    }
}