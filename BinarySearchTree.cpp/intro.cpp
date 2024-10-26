#include<iostream>
#include<queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node() : data(0), left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

Node* insertIntoBST(Node* root, int d) {

    //base 
    if(root == NULL) {

        root = new Node(d);
        return root;
    }

    if(d > root -> data) {

        root -> right = insertIntoBST(root -> right, d);
    }

    else {

        root -> left = insertIntoBST(root -> left, d);
    }

    return root;
}
  
void takeInput(Node* &root) {

    int data;
    cin>>data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

Node* minVal(Node* root) {

    Node* temp = root;

    while(temp -> left != NULL) {

        temp = temp -> left;
    }

    return temp;
}

Node* maxVal(Node* root) {

    Node* temp = root;

    while(temp -> right != NULL) {

        temp = temp -> right;
    }

    return temp;
}

Node* deleteFromBST(Node* root, int val) {

    //base case
    if(root == NULL) {

        return root;
    }

    if(root -> data == val) {

        //0 child 
        if(root -> left == NULL && root -> right == NULL) {

            delete root;
            return NULL;
        }

        //1 child
        
        //left child only
        if(root -> left != NULL && root -> right == NULL) {

            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //right child only
        if(root -> left == NULL && root -> right != NULL) {

            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //2 child
        if(root -> left != NULL && root -> right != NULL) {

            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }

    else if(root -> data > val) {

        root -> left = deleteFromBST(root -> left, val);
        return root;
    }

    else {

        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

void inorder(Node* root) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root -> data << " "; 
    inorder(root -> right);
}

// void levelOrderTraversal(Node *root)
// {
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty())
//     {

//         Node* temp = q.front();
//         q.pop();

//         if (temp == NULL)
//         {
//             cout << endl;

//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }

//         else
//         {
//             cout<<temp -> data <<" "<<endl;
//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }

//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }



int main() {

    Node* root = new Node(10);

    insertIntoBST(root, 20);
    insertIntoBST(root, 30);
    insertIntoBST(root, 40);
    insertIntoBST(root, 50);
    insertIntoBST(root, 60);


    cout<<"printing the bst"<<endl;
    // levelOrderTraversal(root);
    inorder(root);
}