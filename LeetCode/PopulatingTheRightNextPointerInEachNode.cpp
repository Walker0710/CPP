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
    if (!root)
        return nullptr;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *rightNode = nullptr;
        // set rightNode to null initially
        for (int i = q.size(); i; i--)
        {
            // traversing each level
            auto cur = q.front();
            q.pop();
            // pop a node from current level and,
            cur->next = rightNode; // set its next pointer to rightNode
            rightNode = cur;
            // update rightNode as cur for next iteration
            if (cur->right)            // if a child exists
                q.push(cur->right),    // IMP: push right first to do right-to-left BFS
                    q.push(cur->left); // then push left
        }
    }
    return root;
}
