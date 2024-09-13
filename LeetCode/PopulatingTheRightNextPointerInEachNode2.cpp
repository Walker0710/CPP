#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{

    if (root == NULL)
        return NULL;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    queue<Node *> q2;

    while (!q.empty())
    {

        Node *temp1 = q.front();
        q.pop();

        Node *temp2;

        if (q.empty())
            temp2 = NULL;

        else
            temp2 = q.front();

        if (temp1 != NULL)
            temp1->next = temp2;

        if (temp2 == NULL)
            q.pop();

        if (temp2 != NULL && q.size() == 1)
            q.push(NULL);

        if (temp1->left)
            q2.push(temp1->left);

        if (temp1->right)
            q2.push(temp1->right);

        if (q.size() == 0)
        {

            while (!q2.empty())
            {

                Node *toPush = q2.front();
                q2.pop();
                q.push(toPush);
            }
        }
    }

    return root;
}

// 2nd approch
Node *connect(Node *root)
{
    vector<Node *> arr;
    arr.push_back(root);
    if (root == NULL)
        return root;
    while (arr.size() != 0)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == arr.size() - 1)
            {
                arr[i]->next = NULL;
            }
            else
            {
                arr[i]->next = arr[i + 1];
            }
        }
        int n = arr.size(); // store it to prevent runtime infinite condition!
        for (int i = 0; i < n; i++)
        {
            if (arr[i]->left != NULL)
                arr.push_back(arr[i]->left);
            if (arr[i]->right != NULL)
                arr.push_back(arr[i]->right);
        }
        arr.erase(arr.begin(), arr.begin() + n);
    }
    return root;
}