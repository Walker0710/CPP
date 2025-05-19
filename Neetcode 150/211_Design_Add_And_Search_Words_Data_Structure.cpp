#include <bits/stdc++.h>

using namespace std;

// << ,
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

class WordDictionary
{
public:
    trieNode *root;

    WordDictionary()
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

    void addWord(string word)
    {
        insi(root, word);
    }

    bool siri(trieNode *root, string word)
    {
        if (word.length() == 0)
            return root->terminate;

        if (word[0] == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    if (siri(root->children[i], word.substr(1)))
                        return true;
                }
            }
            return false;
        }

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
};