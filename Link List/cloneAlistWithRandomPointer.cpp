#include<iostream>
#include<unordered_map>

using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* arb;

    //constructor
    Node(int d) {

        this -> data = d;
        this -> next = NULL;
        this -> arb = NULL;
    }
};

//1st approch
void insertAtTail(Node* &head, Node* &tail, int d) {

    Node* newNode = new Node(d);
    if(head == NULL) {

        head = newNode;
        tail = newNode;
        return;
    }

    else {

        tail -> next = newNode;
        tail = newNode;
    }
}

Node* copyList(Node* head) {

    //step 1 - creat a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != NULL) {

        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }

    //step 2 - create a map
    unordered_map<Node*, Node*> oldToNew;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL) {

        oldToNew[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL) {

        cloneNode -> arb = oldToNew[originalNode -> arb];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    return cloneHead;
}

//2nd approch
void insertAtTail(Node* &head, Node* &tail, int d) {

    Node* newNode = new Node(d);

    if(head == NULL) {

        head = newNode;
        tail = newNode;
    }

    else {

        tail -> next = newNode;
        tail = newNode;
    }
}


Node* copyList(Node* head) {

    //step1 create a clone list
    Node* cloneHead = NULL;
    Node* colneTail = NULL;

    Node* temp = head;
    while(temp != NULL) {

        insertAtTail(cloneHead, colneTail, temp -> data);
        temp = temp -> next;
    }

    //step2 cloneNode add in btween original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL) {

        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;

        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }

    //step3 random pointer copy
    temp = head;

    while(temp != NULL) {

        if(temp -> next != NULL) {

            if(temp -> arb != NULL) {

                temp -> next -> arb = temp -> arb -> next;
            }

            else {

                temp -> next = temp -> arb;
            }
        }

        temp = temp -> next -> next;
    }

    //step4 revert changes done in step2
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL) {

        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        if(originalNode != NULL) {

            cloneNode -> next = originalNode -> next;
        }
        cloneNode = cloneNode -> next;
    }

    return cloneHead;
}


