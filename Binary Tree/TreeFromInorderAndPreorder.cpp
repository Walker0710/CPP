#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int findPos(int in[], int element, int n)
{

    for (int i = 0; i < n; i++)
    {

        if (in[i] == element)
        {

            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{

    // base case
    if (index == n - 1 || inorderStart > inorderEnd)
    {

        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);
    int positon = findPos(in, element, n);

    root->left = solve(in, pre, index, inorderStart, positon - 1, n);
    root->right = solve(in, pre, index, positon + 1, inorderEnd, n);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{

    int preorderIndex = 0;
    Node *ans = solve(in, pre, preorderIndex, 0, n - 1, n);
    return ans;
}

//2nd
void createMapping(int in[], map<int, int> nodeToIndex, int n)
{

    for (int i = 0; i < n; i++)
    {

        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{

    // base case
    if (index == n - 1 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);
    int positon = nodeToIndex[element];
    root->left = solve(in, pre, index, inorderStart, positon - 1, n, nodeToIndex);
    root->right = solve(in, pre, index, positon + 1, inorderEnd, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{

    int preorderIndex = 0;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node *ans = solve(in, pre, preorderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}