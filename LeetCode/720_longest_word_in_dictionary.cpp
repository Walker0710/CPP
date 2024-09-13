#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// using map
string longestWord(vector<string> &words)
{
    unordered_set<string> wordSet(words.begin(), words.end());
    sort(words.begin(), words.end());

    string longest = "";
    for (const auto &word : words)
    {
        bool flag = true;
        for (int j = 1; j <= word.length(); j++)
        {
            if (wordSet.find(word.substr(0, j)) == wordSet.end())
            {
                flag = false;
                break;
            }
        }
        if (flag && word.length() > longest.length())
        {
            longest = word;
        }
    }
    return longest;
}

// using trie
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
            root->isTerminal = true;

        int index = word[0] - 'A';
        TrieNode *child;

        // is present
        if (root->children[index] != NULL)
            child = root->children[index];

        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUntil(child, word.substr(1));
    }

    void inserWord(string word)
    {

        insertUntil(root, word);
    }

    bool searchUntil(TrieNode *root, string word)
    {

        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'A';
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
};

string longestWord(vector<string> &words)
{
    Trie* root = new Trie();
    for (string x : words)
    {
        root -> inserWord(x);
    }
    string ans = "";
    for (string x : words)
    {
        if (root -> search(x) && x.size() >= ans.size())
        {
            if (x.size() == ans.size())
            {
                ans = min(ans, x);
            }
            else
            {
                ans = x;
            }
        }
    }
    return ans;
}
