#include<iostream>
#include<map>

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

bool isCircular(Node* head) {

    //empty list
    if(head == NULL) {

        return true;
    }

    Node* temp = head -> next;

    while(temp != head && temp != NULL) {

        temp = temp -> next;
    }

    if(temp == head) {

        return true;
    }

    else {

        return false;
    }
}

//first tech 

bool detectLoop(Node* head) {

    if(head == NULL) {

        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp != NULL) {

        //cycle is present 
        if(visited[temp] == true) {

            //cout<<"present on element "<<temp -> data <<endl;  // cycle ka first element dega

            return true;
        }

        visited[temp] = true;

        temp = temp -> next;
    }

    return false;
}


//2nd tech -- floyd cycle detection algo

Node* floydDetectLoop(Node* head) {

    if(head == NULL) {

        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {

        fast = fast -> next;

        if(fast != NULL) {

            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {

            cout<<" present at "<< slow -> data << endl;
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* head) {

    if(head == NULL) {

        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while (slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;   
}

void removeLoop(Node* head) {

    if(head == NULL) {

        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while (temp -> next != startOfLoop) {

        temp = temp -> next;
    }

    temp -> next = NULL;
}







bool isCircular(Node* head){
    if(head == NULL) {

        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {

        fast = fast -> next;

        if(fast != NULL) {

            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            
            if (slow == head)
             return true;
            
            else 
            return false;
        }
    }
    return false;
}

























