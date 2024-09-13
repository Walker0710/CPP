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

Node* uniqueSortedList(Node* head) {

    //empty
    if(head == NULL) {

        return NULL;
    }

    //non empty 
    Node* curr = head;

    while (curr -> next != NULL) {

        if(curr -> data == curr -> next -> data) {

            Node* Next_Next = curr -> next -> next;          
            Node* nodeToDelete = curr -> next;

            delete(nodeToDelete);

            curr -> next = Next_Next;
        }

        else {

            curr = curr -> next;
        }
    }

    return head;
}