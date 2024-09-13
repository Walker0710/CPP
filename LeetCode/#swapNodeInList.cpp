#include<iostream>

using namespace std;

class ListNode {

    public:
    int data;
    ListNode* next;

    //constructor
    ListNode(int d) {

        this -> data = d;
        this -> next = NULL;
    }
};

ListNode* swapNodes(ListNode* head, int k) 
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    ListNode* p1 = head;
    int size = 1;

    while(p1 != NULL)
    {
        size++;
        p1 = p1 -> next;
    }

    p1 = head;

    while(k >= 1) 
    {
        p1 = p1 -> next;
        k--;
    }

    ListNode* p2 = head;
    int k1 = size - k + 1;

    while(p2 != NULL && k1 >= 1)
    {
        p2 = p2 -> next;
        k1--;
    }

    if(p1 != NULL && p2 != NULL) 
    {
        int temp = p2 -> val;
        p2 -> val = p1 -> val;
        p1 -> val = temp;
    }

    return head;
}

ListNode* swapNodes(ListNode* head, int k) 
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode* p1 = head;
    int size = 0;

    while(p1 != NULL)
    {
        size++;
        p1 = p1->next;
    }

    p1 = head;  // Ensure k is within bounds

    while(k > 1)
    {
        p1 = p1->next;
        k--;
    }

    ListNode* p2 = head;
    int k1 = size - k + 1;

    while(p2 && k1 > 0)
    {
        p2 = p2->next;
        k1--;
    }

    if(p1 != NULL && p2 != NULL) 
    {
        int temp = p2->val;
        p2->val = p1->val;
        p1->val = temp;
    }

    return head;
}