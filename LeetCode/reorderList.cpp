#include<iostream>
#include<stack>

using namespace std;

class ListNode {

    public:
    int val;
    ListNode* next;

    //constructor
    ListNode(int d) {

        this -> val = d;
        this -> next = NULL;
    }
}; 

ListNode* reverseList(ListNode* head) {

    if(head == NULL || head -> next == NULL) {

        return head;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = NULL;

    while(curr != NULL) {

        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}
ListNode* getMid(ListNode* head) {
    int size = 0;
    ListNode* curr = head;

    while (curr != NULL) {
        size++;
        curr = curr->next;
    }

    int counter = (size + 1) / 2;
    curr = head;

    while (counter > 1) {
        curr = curr->next;
        counter--;
    }

    return curr;
}

void merge(ListNode* first, ListNode* second) {
    while (first && second) {
        ListNode* firstNext = first->next;
        ListNode* secondNext = second->next;

        first->next = second;
        second->next = firstNext;

        first = firstNext;
        second = secondNext;
    }
}

void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }

    ListNode* firstTail = getMid(head);
    ListNode* secondHead = firstTail->next;
    firstTail->next = NULL;

    secondHead = reverseList(secondHead);

    merge(head, secondHead);
}

    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases
        
        stack<ListNode*> my_stack;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) // Put all nodes in stack
        {
            my_stack.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = my_stack.top();
            my_stack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }