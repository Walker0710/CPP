#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node
struct Node* newNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//first approch

int height(struct Node* node) {

    //base case 
    if(node == NULL)
    return 0;

    int left = height(node -> left);
    int right = height(node -> right);

    return max(left, right) + 1;
}

int diameter(struct Node* root) {

    if(root == NULL) {
        return 0;
    }

    int left = diameter(root -> left);
    int right = diameter(root -> right);
    int combo = height(root -> left) + height(root -> right) + 1;

    int ans = max(left, max(right, combo));

    return ans;
}

//second approch
pair<int, int> diameterFast(Node* root) {

    if(root == NULL) {

        pair<int, int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = diameterFast(root -> left);
    pair<int, int> right = diameterFast(root -> right);

    int leftA = left.first;
    int rightA = right.first;
    int combo = left.second + right.second + 1;
    
    pair<int, int> ans; 
    ans.first = max(leftA, max(rightA, combo));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(struct Node* root) {

    int ans = diameterFast(root).first;
    return ans;
}


