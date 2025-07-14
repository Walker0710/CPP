#include <bits/stdc++.h>

using namespace std;

// << ,

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    int shortestWordLength;
    int shortestWordIndex;

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isTerminal = false;
        shortestWordLength = INT_MAX;
        shortestWordIndex = INT_MAX;
    }
};

void insertUntil(TrieNode *root, const string &word, int wordIndex, int wordLen, int i = 0)
{
    if (i == word.length())
    {
        root->isTerminal = true;
        return;
    }

    int index = word[i] - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];

        if (wordLen < child->shortestWordLength || (wordLen == child->shortestWordLength && wordIndex < child->shortestWordIndex))
        {
            child->shortestWordLength = wordLen;
            child->shortestWordIndex = wordIndex;
        }
    }

    else
    {
        child = new TrieNode(word[i]);
        child->shortestWordLength = wordLen;
        child->shortestWordIndex = wordIndex;

        root->children[index] = child;
    }

    insertUntil(child, word, wordIndex, wordLen, i + 1);
}

void insertWord(TrieNode *root, const string &word, int wordIndex)
{
    int wordLen = word.length();

    if (wordLen < root->shortestWordLength || (wordLen == root->shortestWordLength && wordIndex < root->shortestWordIndex))
    {
        root->shortestWordLength = wordLen;
        root->shortestWordIndex = wordIndex;
    }

    insertUntil(root, word, wordIndex, wordLen);
}

int search(TrieNode *root, const string &word)
{
    TrieNode *curr = root;
    int bestMatchIndex = root->shortestWordIndex;

    for (char ch : word)
    {
        int index = ch - 'a';

        if (!curr->children[index])
            break;

        curr = curr->children[index];
        bestMatchIndex = curr->shortestWordIndex;
    }

    return bestMatchIndex;
}

void freeTrie(TrieNode *node)
{
    if (!node)
        return;
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i])
        {
            freeTrie(node->children[i]);
        }
    }
    delete node;
}

vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
{
    TrieNode *root = new TrieNode('\0');
    int n = wordsContainer.size();

    for (int i = 0; i < n; i++)
    {
        string rev = wordsContainer[i];
        reverse(rev.begin(), rev.end());
        insertWord(root, rev, i);
    }

    vector<int> ans;

    for (auto &query : wordsQuery)
    {
        string rev = query;
        reverse(rev.begin(), rev.end());
        int index = search(root, rev);
        ans.push_back(index);
    }

       freeTrie(root);

    return ans;
}
