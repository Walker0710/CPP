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

Node* sortTwoLists(Node* first, Node* second) {

    if(first == NULL) {

        return second;
    }

    if(second == NULL) {

        return first;
    }

    Node* ans = new Node(-1);

    while(first != NULL && second != NULL)  {

        if(first -> data < second -> data) {

            ans -> next = first;
            ans = first;
            first = first -> next;
        }

        if(first -> data > second -> data) {

            ans -> next = second;
            ans = second;
            second = second -> next;
        }
    }

    while(first != NULL) {

        ans -> next = first;
        ans = first;
        first = first -> next;
    }

    while(second != NULL) {

        ans -> next = second;
        ans = second;
        second = second -> next;
    }

    Node* head = ans -> next;

    return head;
}

//2nd approch 

Node* solve(Node* first, Node* second) {

    //if only one element is present 
    if(first -> next == NULL) {

        first -> next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    while(next1 != NULL && curr2 != NULL) {

        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)) {

            //add node btw the first list
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            //update ponters  
            curr1 = curr2;
            curr2 = next2;
        }

        else {

            //curr1 aur next1 ko aage badhan h
            curr1 = next1;
            next1 = next1 -> next;
            
            if(next1 == NULL) {

                curr1 -> next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node* sortTwoList2nd(Node* first, Node* second) {

    if(first == NULL) {

        return second;
    }

    if(second == NULL) {

        return first;
    }

    if(first -> data <= second -> data) {

        solve(first, second);
    }

    else {

        solve(second, first);
    }
}






