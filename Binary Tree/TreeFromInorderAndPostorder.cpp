#include<iostream>
#include<map>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void createMapping(int in[], map<int, int> nodeToIndex, int n)
{

    for (int i = 0; i < n; i++)
    {

        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{
    // base case
    if (index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = post[index--];
    Node *root = new Node(element);
    int positon = nodeToIndex[element];
    root->right = solve(in, post, index, positon + 1, inorderEnd, n, nodeToIndex);
    root->left = solve(in, post, index, inorderStart, positon - 1, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int post[], int n) {

    int postorderIndex = n-1;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node *ans = solve(in, post, postorderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}