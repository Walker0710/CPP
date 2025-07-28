#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[27];
    bool isTerminal; // Corrected variable name

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 27; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false; // Corrected variable name
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUntil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = 0;

        if (word[0] == '/')
            index = 26;

        else
        {
            index = word[0] - 'a';
        }

        TrieNode *child;

        // is present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUntil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUntil(root, word);
    }

    void dfsSolve(TrieNode *root, string toPush, vector<string> &ans)
    {
        if (root->isTerminal)
        {
            ans.push_back(toPush);
            return;
        }

        for (int i = 0; i < 27; i++)
        {
            if (root->children[i])
            {
                // toPush = toPush + root->children[i]->data;
                dfsSolve(root->children[i], toPush + root->children[i]->data, ans);
            }
        }
    }

    vector<string> dfs()
    {
        vector<string> ans;
        dfsSolve(root, "", ans);
        return ans;
    }
};

vector<string> removeSubfolders(vector<string> &folder)
{
    Trie *root = new Trie();
    // sort(folder.begin(), folder.end());

    for (auto i : folder)
    {
        root->insert(i);
    }

    vector<string> ans = root->dfs();
    return ans;
}

// 2nd
struct Node
{
    Node *links[27];
    int ew = 0;
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string &s)
    {
        int n = s.size();
        Node *temp = root;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '/')
            {
                if (temp->links[26] == NULL)
                {
                    Node *newnode = new Node();
                    temp->links[26] = newnode;
                }
                temp = temp->links[26];
            }
            else
            {
                if (temp->links[s[i] - 'a'] == NULL)
                {
                    Node *newnode = new Node();
                    temp->links[s[i] - 'a'] = newnode;
                }
                temp = temp->links[s[i] - 'a'];
            }
        }
        temp->ew++;
    }

    bool check(string &s)
    {
        Node *temp = root;
        int n = s.size();
    
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '/')
            {

                if (temp->ew > 0)
                {
                    return true;
                }
                temp = temp->links[26];
            }
    
            else
            {
                if (temp->links[s[i] - 'a'] == NULL)
                {
                    return false;
                }
                temp = temp->links[s[i] - 'a'];
            }
        }
    
        return false;
    }
};


class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        Trie T;

        for (int i = 0; i < folder.size(); i++)
        {
            T.insert(folder[i]);
        }
        vector<string> ans;
        for (int i = 0; i < folder.size(); i++)
        {
            if (T.check(folder[i]))
            {
                continue;
            }
            else
            {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};