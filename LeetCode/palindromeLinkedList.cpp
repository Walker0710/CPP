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

ListNode* getMid(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {

        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

ListNode* reverse(ListNode* head) {

    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* Next = NULL;

    while(curr != NULL) {

        Next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = Next; 
    }

    return prev;
}

bool ispalindrome(ListNode* head) {

    if(head -> next == NULL) {

        return true;
    }

    ListNode* middle = getMid(head);

    //reversing the list after the middle
    ListNode* temp = middle -> next;
    middle -> next = reverse(temp);

    ListNode* head1 = head;
    ListNode* head2 = middle -> next;

    while(head2 != NULL) {

        if(head1 -> data != head2 -> data) {

            return false;
        }

        else {

            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    }

    // ye part optional h bas apan list ko jasi thi wase he bna de rhe h wapas
    temp = middle -> next;
    middle -> next = reverse(temp);

    return true;
}