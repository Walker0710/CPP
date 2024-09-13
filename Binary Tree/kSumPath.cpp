#include<iostream>
#include<vector>

using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// time complex = n2 shyd
void solve(Node* root, int k, int &count, vector<int> path) {

    //base case
    if(root == NULL) {

        return ;
    }

    path.push_back(root -> data);

    solve(root -> left, k, count, path);
    solve(root -> right, k, count, path);

    int sum = 0;

    for(int i = path.size() - 1; i>=0; i--) {

        sum = sum + path[i];

        if(sum == k) {

            count++;
        }
    }

    path.pop_back();
}

int sumK(Node *root,int k) {

    vector<int> path;
    int count = 0;
    solve(root, k, count, path);

    return count;
}