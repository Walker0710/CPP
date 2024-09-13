#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void leftpart(Node *root, vector<int> &ans)
{

    if (root == NULL)
    {

        return;
    }

    if (root->left)
    {
        leftpart(root->left, ans);
    }

    ans.push_back(root->data);
}

void rightpart(Node *root, vector<int> &ans)
{

    if (root == NULL)
    {

        return;
    }

    ans.push_back(root->data);

    if (root->right)
    {
        rightpart(root->right, ans);
    }
}

vector<int> topView(Node *root)
{

    vector<int> ans;
    if (root == NULL)
    {

        return ans;
    }

    leftpart(root->left, ans);
    ans.push_back(root->data);
    rightpart(root->right, ans);
}

// 2nd & the only approch
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for a HD, then do nothing
        if (topNode.find(hd) == topNode.end()) //smh nhi aayi
            topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}