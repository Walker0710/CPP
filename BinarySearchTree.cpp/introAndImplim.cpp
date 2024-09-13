#include<iostream>
#include<queue>

using namespace std;

class Node {

    int data;
    Node* left;
    Node* right;

    Node(int d) {

        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

