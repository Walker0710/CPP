#include <iostream>

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
            children[i] = NULL;

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

        if (word.length() == 0)
            root->isTerminal = true;

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];

        else
        {

            child = new TrieNode(word[0]);
            root->children[index] = child;
            child = root->children[index];
        }

        insertUntil(child, word.substr(1));
    }

    void insert(string word)
    {

        insertUntil(root, word);
    }

    bool searchUntil(TrieNode *root, string word)
    {

        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];

        else
            return false;

        return searchUntil(child, word.substr(1));
    }

    bool search(string word)
    {

        return searchUntil(root, word);
    }

    bool startsWithUntil(TrieNode *root, string word)
    {

        if (word.length() == 0)
            return true;

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];

        else
            return false;

        return searchUntil(child, word.substr(1));
    }

    bool startsWith(string prefix)
    {

        return startsWithUntil(root, prefix);
    }
};

// 2nd approch
class trieNode
{
public:
    char value;
    trieNode *children[26];
    bool terminate;

    trieNode(char value)
    {
        this->value = value;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        this->terminate = false;
    }
};
class Trie
{
public:
    trieNode *root;
    Trie()
    {
        root = new trieNode('\0');
    }
    void insi(trieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->terminate = true;
            return;
        }

        int index = word[0] - 'a';
        trieNode *temp;
        if (root->children[index] != NULL)
        {
            temp = root->children[index];
        }
        else
        {
            temp = new trieNode(word[0]);
            root->children[index] = temp;
            temp = root->children[index];
        }
        insi(temp, word.substr(1));
    }

    void insert(string word)
    {
        insi(root, word);
    }

    bool siri(trieNode *root, string word)
    {
        if (word.length() == 0)
            return root->terminate;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            return siri(root->children[index], word.substr(1));
        }
        return false;
    }

    bool search(string word)
    {
        return siri(root, word);
    }

    bool pre(trieNode *root, string word)
    {
        if (word.length() == 0)
            return true;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            return pre(root->children[index], word.substr(1));
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        return pre(root, prefix);
    }
};