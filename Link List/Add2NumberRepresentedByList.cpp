#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    private: 
    void insertAtTail(struct Node* &head,struct Node* &tail, int d) {

    //new node create
    Node* temp = new Node(d);

    if(head == NULL) {

        head = temp;
        tail = temp;
        return ;
    }

    else {
    tail -> next = temp;
    tail = temp;
    }
}

struct Node* reverse(struct Node* head) {

    Node* curr = head;
    Node* prev = NULL;
    Node* Next = NULL;

    while(curr != NULL) {

        Next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = Next;
    }

    return prev;
}

struct Node* add(struct Node* first,struct Node* second) {

    int sum = 0;
    int carry = 0;
    int digit;

    struct Node* ansHead = NULL;
    struct Node* ansTail = NULL;

    while(first != NULL && second != NULL) {

        sum = first -> data + second -> data + carry;

        carry = sum/10;
        digit = sum%10;

        insertAtTail(ansHead, ansTail, digit);

        first = first -> next;
        second = second -> next;
    }

    while(first != NULL) {

        int sum = carry + first -> data;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        first = first -> next;
    }

    while(second != NULL) {

        int sum = carry + second -> data;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        second = second -> next;
    }

    while(carry != 0) {

        int sum = carry;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
    }

    return ansHead;
}
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
    first = reverse(first);
    second = reverse(second);

    struct Node* ans = add(first, second);

    ans = reverse(ans);

    return ans;
    }
};