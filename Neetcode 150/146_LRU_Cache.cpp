#include <bits/stdc++.h>

using namespace std;

// << ,

class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap = 0;
    unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node *temp = head -> next;

        newNode -> next = temp;
        newNode -> prev = head;

        head -> next = newNode;
        temp -> prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevv = delNode -> prev;
        Node* nextt = delNode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }

    int get(int key)
    {
        if(m.find(key) != m.end()) {
            Node* res = mp[key];
            int ans = res -> val;

            m.erase(key);
            deleteNode(res);
            addNode(res);

            mp[key] = head -> next;
            return ans;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()) {
            Node* curr = m[key];
            mp.erase(key);
            deleteNode(curr);
        }

        if(m.size()) {
            mp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};