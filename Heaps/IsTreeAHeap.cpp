#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int countNode(Node* root) {

    if(root == NULL)
    return 0;

    int count = 0;

    int left = countNode(root -> left);
    int right = countNode(root -> right);

    int ans = 1 + left + right;
    return ans;
}

bool isMAX(Node* root) {

    if(root -> right == NULL || root -> left == NULL)
    return true;

    if(root -> right == NULL)
    return root -> data > root -> right -> data;

    else {

        bool left = isMAX(root -> left);
        bool right = isMAX(root -> right);

        return (left && right && (root -> data > root -> left -> data && root -> data > root -> right -> data));
    }
}

bool isCBT(Node* root, int index, int cnt) {

    if(root == NULL)
    return true;

    if(index >= cnt) 
    return false;

    bool left = isCBT(root -> left, 2*index + 1, cnt);
    bool right = isCBT(root -> right, 2*index + 2, cnt);

    return left && right;
}

bool isHeap(struct Node* tree) {

    int index = 0;
    int totalCount = countNode(tree);
    if(isCBT(tree, index, totalCount) && isMAX(tree))
    return true;

    else 
    return false;
} 