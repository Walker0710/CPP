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

//1st approch

Node* sortList(Node *head) {

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    while(temp != NULL) {

        if(temp -> data == 0) {

            zeroCount++;
        }

        if(temp -> data == 1) {

            oneCount++;
        }

        if(temp -> data == 2) {

            twoCount++;
        }

        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL) {

        if(zeroCount != 0) {

            temp -> data = 0;
            zeroCount--;
        }

        else if(oneCount != NULL) {

            temp -> data = 1;
            oneCount--;
        }

        else if(twoCount != NULL) {

            temp -> data = 2;
            twoCount--;
        }

        temp = temp -> next;
    }

    return head;
}



//2nd approch

void insertAtTail(Node* &tail, Node* curr) {

    tail -> next = curr;
    tail = curr;
}

Node* sortList2nd(Node* head) {

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    //creating seprate list

    while(curr != NULL) {

        int value = curr -> data;

        if(value == 0) {

            insertAtTail(zeroTail, curr);
        }

        if(value == 1) {

            insertAtTail(oneTail, curr);
        }

        if(value == 2) {

            insertAtTail(twoTail, curr);
        }

        curr = curr -> next;
    }

    //merge 3 sublist

    //1s list is nonempty
    if(oneHead -> next != NULL) {

        zeroTail -> next = oneHead -> next;
    }
 
    //1s list is empty  
    else {

        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    //setup head
    head = zeroHead -> next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}