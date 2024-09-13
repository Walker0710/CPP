#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

// class TrieNode
// {
// public:
//     char data;
//     TrieNode *children[26];
//     bool isTerminal;

//     TrieNode(char ch)
//     {
//         data = ch;

//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = NULL;
//         }

//         isTerminal = false;
//     }
// };

// class Trie
// {
// public:
//     TrieNode *root;

//     Trie()
//     {
//         root = new TrieNode('\0');
//     }

//     void insertUntil(TrieNode *root, string word)
//     {
//         // base case
//         if (word.length() == 0)
//         {
//             root->isTerminal = true;
//             return;
//         }

//         char ch = word[0];
//         int index = tolower(ch) - 'a'; // Handle both uppercase and lowercase
//         TrieNode *child;

//         // is present
//         if (root->children[index] != NULL)
//         {
//             child = root->children[index];
//         }
//         else
//         {
//             child = new TrieNode(ch);
//             root->children[index] = child;
//         }

//         insertUntil(child, word.substr(1));
//     }

//     void insertWord(string word)
//     {
//         insertUntil(root, word);
//     }
// };

// void traversal(TrieNode *root, int curr, vector<int> ans)
// {
//     if (root == NULL)
//         return;

//     if (root->isTerminal)
//     {
//     }
// }

// vector<int> lexicalOrder(int n)
// {
//     Trie *t = new Trie();

//     for (int i = 1; i <= n; i++)
//     {
//         t->insertWord(to_string(i));
//     }

//     vector<int> ans;
//     traversal(t, 0, ans);
//     return ans;
// }

struct Node
{
    Node *links[10];
    bool flag = false;
    bool isContains(char ch)
    {
        return links[ch - '0'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - '0'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - '0'];
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!(node->isContains(word[i])))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->flag = true;
    }
};

void traverseTrie(Node *root, int curr, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->flag)
    {
        ans.push_back(curr);
    }
    for (char ch = '0'; ch <= '9'; ch++)
    {
        if (root->isContains(ch))
        {
            traverseTrie(root->get(ch), (curr * 10) + (ch - '0'), ans);
        }
    }
}

vector<int> lexicalOrder(int n)
{
    Trie trie;
    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        trie.insert(s);
    }
    vector<int> ans;
    traverseTrie(trie.root, 0, ans);
    return ans;
}