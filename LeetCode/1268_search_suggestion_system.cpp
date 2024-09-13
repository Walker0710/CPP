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
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

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

        char ch = word[0];
        int index = tolower(ch) - 'a'; // Handle both uppercase and lowercase
        TrieNode *child;

        // is present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        insertUntil(child, word.substr(1));
    }

    void inserWord(string word)
    {
        insertUntil(root, word);
    }

    void printSuggestion(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            if (temp.size() <= 3)
                temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> ans;

        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            prefix.push_back(ch);
            vector<string> toPush;

            int index = tolower(ch) - 'a'; // Handle both uppercase and lowercase
            TrieNode *curr = prev->children[index];

            if (curr == NULL)
            {
                break;
            }

            printSuggestion(curr, toPush, prefix);

            ans.push_back(toPush);
            toPush.clear();
            prev = curr;
        }

        return ans;
    }
};

vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
    Trie *t = new Trie();

    for (int i = 0; i < products.size(); i++)
    {
        string yo = products[i];
        t->inserWord(yo);
    }

    return t->getSuggestion(searchWord);
}

// 2nd
class Trie
{
    struct Node
    {
        bool isWord = false;
        vector<Node *> children{vector<Node *>(26, NULL)};
    } *Root, *curr;

    void dfs(Node *curr, string &word, vector<string> &ans)
    {
        if (ans.size() == 3)
            return;
        if (curr->isWord)
            ans.push_back(word);

        for (char c = 'a'; c <= 'z'; c++)
        {
            if (curr->children[c - 'a'])
            {
                word += c;
                dfs(curr->children[c - 'a'], word, ans);
                word.pop_back();
            }
        }
    }

public:
    Trie()
    {
        Root = new Node;
    }

    void insert(string &s)
    {
        curr = Root;
        for (char &c : s)
        {
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new Node();
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }

    vector<string> getwords(string &prefix)
    {
        curr = Root;
        vector<string> res;

        for (char &c : prefix)
        {
            if (!curr->children[c - 'a'])
                return res;
            curr = curr->children[c - 'a'];
        }
        dfs(curr, prefix, res);
        return res;
    }
};

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        Trie trie = Trie();
        vector<vector<string>> res;
        for (string &w : products)
            trie.insert(w);
        string prefix;
        for (char &c : searchWord)
        {
            prefix += c;
            res.push_back(trie.getwords(prefix));
        }
        return res;
    }
};

// 3rd crazyy solution
vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
    vector<vector<string>> result(searchWord.size());
    sort(products.begin(), products.end());

    int start = 0, end = products.size() - 1;

    for (int i = 0; i < searchWord.size(); i++)
    {
        char ch = searchWord[i];

        while (start <= end && (products[start].size() <= i || products[start][i] != ch))
            start++;

        while (start <= end && (products[end].size() <= i || products[end][i] != ch))
            end--;

        int remain = end - start + 1, j = 0;
        while (j < min(3, remain))
        {
            result[i].push_back(products[start + j]);
            j++;
        }
    }

    return result;
}