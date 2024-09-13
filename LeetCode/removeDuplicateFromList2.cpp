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

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) {

        return head;
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* p1 = dummy;
    ListNode* p2 = head;

    while (p2 != NULL) {

        if (p2->next != NULL && p2->data == p2->next->data) {

            // Skip duplicate nodes
            while (p2->next != NULL && p2->data == p2->next->data) {

                p2 = p2->next;
            }
            p1->next = p2->next;
        } 
        else {
            // Move to the next distinct node
            p1 = p1->next;
        }
        p2 = p2->next;
    }

    ListNode* result = dummy->next;
    delete dummy;

    return result;
}

