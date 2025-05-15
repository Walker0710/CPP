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

ListNode* removeNthFromEnd(ListNode* head, int n) {

    if (head == NULL || n <= 0) {

        return head;
    }

    int size = 1;
    ListNode* yo = head;

    while(yo -> next != NULL) {

        yo = yo -> next;
        size++;
    }

    if(n == size) {

        return head -> next;
    }

    else if(n == 1) {

        int count = size - 2;
        ListNode* curr = head;

        while(count) {

            curr = curr -> next;
            count--;
        }

        curr -> next = NULL;
        return head;
    }

    else {
        ListNode* prev = head;
        ListNode* curr = head -> next;
        int count = size - n - 1;

        while(count) {
    
            prev = prev -> next;
            curr = curr -> next;
            count--;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        return head;
    }
}



