#include <bits/stdc++.h>

using namespace std;

// << ,

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfs(Node *node, unordered_map<Node *, Node *> &map)
{
    Node *copy = new Node(node->val);
    map[node] = copy;

    for (auto neigh : node->neighbors)
    {
        if (map.find(neigh) != map.end())
        {
            copy->neighbors.push_back(map[neigh]);
        }
        else
        {
            dfs(neigh, map);
            copy->neighbors.push_back(map[neigh]);
        }
    }
}

Node *cloneGraph(Node *node)
{
    if (node == NULL)
        return NULL;

    unordered_map<Node *, Node *> map;
    dfs(node, map);

    return map[node];
}