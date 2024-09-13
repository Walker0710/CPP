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

Node *removeDuplicates(Node *head) {

    //empty list
    if(head == NULL) {

        return NULL;
    }

    //non empty list
    Node* curr = head;

    while(curr != NULL) {

        Node* temp = curr -> next;
        Node* tempprev = curr;

        while(temp != NULL) {

            if(curr -> data == temp -> data) {

                Node* Next = temp -> next;
                Node* nodeToDelete = temp;
                delete(nodeToDelete);
                tempprev -> next = Next;
            }

            else {

                temp = temp -> next;
                tempprev = tempprev -> next;
            }
        }

        curr = curr -> next;
    }

    return head;
}

//2nd approch