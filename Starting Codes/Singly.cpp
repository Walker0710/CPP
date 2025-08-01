#include<iostream>

using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {

        this -> data = data;
        this -> next = NULL;
    }

    //distructor
    ~Node() {

        int value = this -> data;

        //memory free
        if(this -> next != NULL) {

            delete next;
            this -> next = NULL;
        }

        cout<<" memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, int d) {

    //new node create
    Node*temp = new Node(d);
    temp -> next = head;    // temp ka jo next h wo next wli heaad ko point karega
    head = temp;
}

void insertAtTail(Node* &tail, int d) {

    //new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    temp = tail -> next; //check it ki wo tail temp hoga kya
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {

    if(position == 1) {

        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1) {

        temp = temp->next;
        cnt++;
    }

    //inserting at last position
    if(temp -> next == NULL) {

        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deletion(int position, Node* & head) {

    //deleting first or start node
    if(position == 1) {

        Node* temp = head;
        head = head -> next;

        //memory free start node
        temp -> next = NULL;
        delete temp; 
    }

    else {

        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {

            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &head) {

    Node* temp = head;

    while(temp != NULL) {

        cout<< temp -> data <<" ";
        temp = temp -> next;
    }

    cout<<endl;
}

int main() {

    //creat a new node
    Node* node1 = new Node(10);

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtTail(tail,12);

    print(head);

    insertAtTail(tail, 15);

    print(head);

    insertAtPosition(head, tail, 4, 22);
    print(head);

    cout<<"Head "<< head->data<<endl;
    cout<<"Tail "<< tail->data<<endl;

    deletion(1, head);
    print(head); 

    return 0;
}