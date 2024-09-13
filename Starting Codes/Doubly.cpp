#include<iostream>

using namespace std;

class Node {

    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d) {

        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node() {

        int val = this -> data;
        if(next != NULL) {

            delete next;
            next = NULL;
        }

        cout<<"memory free for node with data "<<val<<endl;
    }
};

void print(Node* head) {

    Node* temp = head;

    while(temp != NULL) {

        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

    cout<<endl;
}

int getLength(Node* head) {

    int len = 0;
    Node* temp = head;

    while(temp != NULL) {

        len++;
        temp = temp -> next;
    }

    return len;
}

void insertAtHead(Node* &head,Node* &tail, int d) {

    if(head == NULL) {

        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else {

    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head =  temp;

    }
}

void insertaAtTail(Node* &head, Node* &tail, int d) {

    if(tail == NULL) {

        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }

    else {

    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d) {

    if(pos == 1) {

        insertAtHead(head, tail, d);
        return ;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < pos - 1) {

        temp = temp->next;
        cnt++;
    }

    //inserting at last pos
    if(temp -> next == NULL) {

        insertaAtTail(head, tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeRToInsert = new Node(d);

    nodeRToInsert -> next = temp -> next;
    temp -> next -> prev = nodeRToInsert;
    temp -> next = nodeRToInsert;
    nodeRToInsert -> prev = temp;
}

void deleteNode(int pos, Node* &head) {

    //deleting first or start node
    if(pos == 1) {

        Node* temp = head;
        temp -> next-> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }

    else {

        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < pos) {

            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout<< getLength(head)<<endl;

    insertAtHead(head, tail, 11);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertaAtTail(head, tail, 25);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


    deleteNode(1,head);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


    return 0;
}