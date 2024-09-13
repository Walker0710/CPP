#include<iostream>

using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int d) {

        this -> data = d;
        this -> next = NULL;
    }
};

//iterato tech

Node* reverseList(Node* head) {

    if(head == NULL || head -> next == NULL) {

        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {

        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

//recursive tech

void reverse(Node* &head, Node* curr, Node* prev) {

    //base case
    if(curr == NULL) {

        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverse(head, forward, curr);
    curr -> next = prev;
}

Node* reverseLinkList(Node* head) {

    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}


// 3rd approch

Node* reverse1(Node* head) {

    //base case
    if(head == NULL || head -> next == NULL) {

        return head;
    }

    int chotaHead = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return chotaHead;
}
