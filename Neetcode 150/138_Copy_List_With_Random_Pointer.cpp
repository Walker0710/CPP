#include <bits/stdc++.h>

using namespace std;

// << ,

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

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

Node *copyRandomList(Node *head)
{

    Node *CloneHead = NULL;
    Node *CloneTail = NULL;

    Node *temp = head;

    while(temp != NULL) {
        insertAtTail(CloneHead, CloneTail, temp -> val);
        temp = temp -> next;       
    }

    unordered_map<Node *, Node *> mp;

    Node *orignal = head;
    Node *clone = CloneHead;

    while (orignal != NULL)
    {
        mp[orignal] = clone;
        orignal = orignal -> next;
        clone = clone -> next;
    }

    orignal = head;
    clone = CloneHead;

    while (orignal != NULL)
    {
        clone -> random = mp[orignal -> random];
        orignal = orignal -> next;
        clone = clone -> next;
    }

    return CloneHead;
}