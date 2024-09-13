#include<iostream>
#include<vector>
#include<queue>

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

vector <int> zigZagTraversal(Node* root) {

    vector<int> result;
    if(root == NULL) {

        return result;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {

        int size = q.size();
        vector<int> ans(size);

        for(int i = 0; i<size; i++) {

            Node* frontnode = q.front();
            q.pop();
   
            //choosing between normal or reverse insert
            int index = leftToRight ? i : size - i -1;
            ans[index] = frontnode -> data;

            if(frontnode -> left) {

                q.push(frontnode -> left);
            }

            if(frontnode -> right) {

                q.push(frontnode -> right);
            }
        }
        
        //direction change 
        leftToRight = !leftToRight;

        for(auto i: ans) {

            result.push_back(i);
        }
    }

    return result;
}