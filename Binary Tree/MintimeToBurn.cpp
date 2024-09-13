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

Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParents)
{

    Node *res = NULL;
    queue<Node *> q;

    q.push(root);
    nodeToParents[root] = NULL;

    while (!q.empty())
    {

        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {

            res = front;
        }

        if (front->left)
        {

            nodeToParents[front->left] = front;
            q.push(front->left);
        }

        if (front->right)
        {

            nodeToParents[front->right] = front;
            q.push(front->right);
        }
    }
}

int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{

    map<Node *, bool> visited;
    queue<Node *> q;

    int ans = 0;

    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {

        bool flag = false;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {

            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {

                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            if (front->right && !visited[front->right])
            {

                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {

                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }

        if (flag)
        {

            ans++;
        }
    }

    return ans;
}

int minTime(Node *root, int target)
{

    // algo
    // 1. create nodeToParent mapping
    // 2. find target node
    // 3. burn the tree in min time

    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}