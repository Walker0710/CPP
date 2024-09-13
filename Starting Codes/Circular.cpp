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

    ~Node() {

        int value = this->data;
        if(this -> next != NULL) {

            delete next;
            next = NULL;
        } 

        cout<<"memory is free for node with data "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int d) {

    //empty list
    if(tail == NULL) {

        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }

    //non empty list
    else {

        Node* curr = tail;

        while (curr -> data != element) 
        {
            curr = curr -> next;
        }

        //elemnt found -> curr is reperesenting element wla node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
        
    }
}

void print(Node* tail) {

    if(tail == NULL) {

        cout<<" list is empty"<<endl;
        return ;
    }

    Node* temp = tail;

    do {

        cout<<tail -> data <<" ";
        tail = tail -> next;
    }

    while(tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {

        cout<<" list id empty, please check again "<<endl;
        return ;
    }

    else {

        //non empty
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {

            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node link list
        if(tail == curr) {

            tail = NULL;
        }

        //>=2 Node linked list   
        else if(tail == curr) {

            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

int main() {

    Node* tail = NULL;

    //empty list me insert kre h
    insertNode(tail, 999, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    deleteNode(tail, 10);
    print(tail);

    return 0;
    
}