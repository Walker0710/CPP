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

    if(head == NULL || head -> next == NULL) {

        return head;
    }

    ListNode* p1 = head;
    ListNode* p2 = head -> next;

    while (p2 != NULL) {

        if(p1 -> data == p2 -> data) {

            ListNode* fur = p2 -> next;
            p1 -> next = fur;
            p2 -> next = NULL;
            delete(p2);
            p2 = fur;
        }

        else {

            p1 = p1 -> next;
            p2 = p2 -> next;
        }
    }

    return head;
}