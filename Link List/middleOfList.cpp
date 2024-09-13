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

int getLenth(Node* head) {

    int len = 0;

    while(head != NULL) {

        len++;
        head = head -> next;
    }

    return len;
}

Node* findMiddle(Node* head) {

    int len = getLenth(head);
    int yo = (len/2);

    Node* temp = head;
    int cnt = 0;

    while(cnt < yo) {

        temp = temp -> next;
        cnt++;
    }

    return temp;
}

//2nd approch

Node* getMiddle(Node* head) {

    if(head == NULL || head -> next == NULL) {

        return head;
    }

    //2 nodes
    if(head -> next -> next == NULL) {

        return head -> next;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL) {

        fast = fast -> next;

        if(fast != NULL) {

            fast = fast -> next;
        }

        slow = slow -> next;
    }

    return slow;
}

Node* findMiddle(Node* head) {

    return getMiddle(head);
}

